all: clear pointers linkedlist
pointers:
	@echo " "
	@echo "==============================="
	@echo "|          PONTEIROS          |"
	@echo "==============================="
	@echo "Compilando o exemplo de ponteiros. Programa pointers"
	gcc Pointers.c -o pointers
	chmod +x pointers
linkedlist:
	@echo " "
	@echo "==============================="
	@echo "|            LISTA            |"
	@echo "==============================="
	@echo "Compilando o biblioteca LinkedList. Programa LinkedListTest"
	gcc LinkedList.c LinkedList.h LinkedListTest.c log.h log.c -o linkedlist
	chmod +x linkedlist
clear:
	@echo " "
	@echo "==============================="
	@echo "|    REMOVENDO PROGRAMAS      |"
	@echo "==============================="
	@echo "Removendo os arquivos compilados"
	rm -f pointers
	rm -f linkedlist