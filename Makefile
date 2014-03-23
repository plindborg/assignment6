INSTDIR = /usr/local/bin
LIBINSTDIR = /usr/local/lib
CC = gcc # C compiler
CFLAGS = -fPIC -Wall -Wextra -Werror -O2 -c -std=c99 # C flags
LDFLAGS = -shared -o  # linking flags
RM = rm -f  # rm command

all: main.c component/component.c resistance/resistance.c power/power.c
	$(CC) $(CFLAGS) component/component.c
	$(CC) $(LDFLAGS) lib/libcomponent.so component.o
	$(CC) $(CFLAGS)  resistance/resistance.c
	$(CC) $(LDFLAGS) lib/libresistance.so resistance.o
	$(CC) $(CFLAGS)  power/power.c
	$(CC) $(LDFLAGS) lib/libpower.so power.o
	$(CC) -L$(CURDIR)/lib -Wall -o electrotest main.c -lcomponent -lresistance -lpower

resistance: resistance/resistance.c
	$(CC) $(CFLAGS) resistance/resistance.c
	$(CC) $(LDFLAGS) lib/libresistance.so resistance.o 

component: component/component.c
	$(CC) $(CFLAGS) component/component.c
	$(CC) $(LDFLAGS) lib/libcomponent.so component.o

power: power/power.c
	$(CC) $(CFLAGS) power/power.c
	$(CC) $(LDFLAGS) lib/libpower.so power.o

install: main.c lib/libpower.so lib/libcomponent.so lib/libresistance.so
	@if [ -d $(LIBINSTDIR) ];\
	then \
		cp lib/*.so $(LIBINSTDIR);\
		chmod 0755 $(LIBINSTDIR)/libpower.so;\
		chmod 0755 $(LIBINSTDIR)/libresistance.so;\
		chmod 0755 $(LIBINSTDIR)/libcomponent.so;\
		ldconfig;\
		$(CC) -L$(LIBINSTDIR) -Wall -o electrotest main.c -lcomponent -lresistance -lpower;\
	else \
		echo "$(LIBINSTDIR) kunde inte hittas";\
	fi;
	
	@if [ -d $(INSTDIR) ]; \
	then \
		cp electrotest $(INSTDIR);\
		chmod a+x $(INSTDIR)/electrotest;\
		chmod og-w $(INSTDIR)/electrotest;\
		echo "Installerat i $(INSTDIR)";\
	else \
		echo "$(INSTDIR) kunde inte hittas"; \
	fi;	

uninstall:
	@echo "Entering $(LIBINSTDIR)"
	$(RM) $(LIBINSTDIR)/libpower.so
	$(RM) $(LIBINSTDIR)/libresistance.so
	$(RM) $(LIBINSTDIR)/libcomponent.so
	@echo "Entering $(INSTDIR)"
	$(RM) $(INSTDIR)/electrotest
	@echo "electotest uninstalled"

clean:
	@echo "Cleaning up"
	$(RM) *.o
	$(RM) lib/*.so
	$(RM) electrotest

.PHONY: all power component resistance
