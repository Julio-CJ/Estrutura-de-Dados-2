all: clean pointers linkedlist doublylinkedlist generalizedlinkedlist
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
doublylinkedlist:	
	@echo " "
	@echo "==============================="
	@echo "|         LISTA-DUPLA         |"
	@echo "==============================="
	@echo "Compilando o biblioteca DoublyLinkedList. Programa DoublyLinkedListTest"
	gcc DoublyLinkedList.c DoublyLinkedList.h DoublyLinkedListTest.c log.h log.c -o doublylinkedlist
	chmod +x doublylinkedlist
generalizedlinkedlist:	
	@echo " "
	@echo "==============================="
	@echo "|      LISTA-GENERALIZADA     |"
	@echo "==============================="
	@echo "Compilando o biblioteca GeneralizedLinkedList. Programa GeneralizedLinkedListTest"
	gcc GeneralizedLinkedList.c GeneralizedLinkedList.h GeneralizedLinkedListTest.c log.h log.c -o generalizedlinkedlist
	chmod +x generalizedlinkedlist
clean:
	@echo " "
	@echo "==============================="
	@echo "|    REMOVENDO PROGRAMAS      |"
	@echo "==============================="
	@echo "Removendo os arquivos compilados"
	rm -f pointers
	rm -f linkedlist
	rm -f doublylinkedlist
	rm -f generalizedlinkedlist