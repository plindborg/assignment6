INSTDIR = /usr/local/bin
LIBINSTDIR = /usr/local/lib

all: 
	gcc -c -Wall -Werror -fpic component/component.c
	gcc -shared -o lib/libcomponent.so component.o
	gcc -c -Wall -Werror -fpic -std=c99  resistance/resistance.c
	gcc -shared -o lib/libresistance.so resistance.o
	gcc -c -Wall -Werror -fpic -std=c99  power/power.c
	gcc -shared -o lib/libpower.so power.o
	gcc -L$(CURDIR)/lib -Wall -o electrotest main.c -lcomponent -lresistance -lpower

resistance:
	gcc -c -Wall -Werror -fpic -std=c99  resistance/resistance.c
	gcc -shared -o lib/libresistance.so resistance.o 

install:
	@if [ -d $(LIBINSTDIR) ];\
	then \
		cp lib/*.so $(LIBINSTDIR);\
		chmod 0755 $(LIBINSTDIR)/libpower.so;\
		chmod 0755 $(LIBINSTDIR)/libresistance.so;\
		chmod 0755 $(LIBINSTDIR)/libcomponent.so;\
		ldconfig;\
		gcc -L$(LIBINSTDIR) -Wall -o electrotest main.c -lcomponent -lresistance -lpower;\
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
