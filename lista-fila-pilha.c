#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tam 1000

typedef struct Node{
	char title[tam];
	struct Node *next;
}node;
void bye(){

	printf("Thank you.\n");
}
node *addPilha(node *pilha, char title[tam]){
	node *cur=pilha;
	node *new=(node *) malloc(sizeof(node));// cria novo nó.
	strcpy(new->title,title);// insere seu novo registro no novo nó.
	new->next = NULL;
	
	if(cur->next==NULL){
		pilha->next= new; // caso a pilha esteja vazia, o novo elemento será o primeiro da pilha.
	}
	else{
	cur=cur->next; // caso a pilha não esteja vazia, o primeiro elemento será realocado para a segunda posição, tornando o novo elemento
	pilha->next = new; // o primeiro da pilha.
	new->next = cur;
	}
	return pilha;// retorna pilha atualizada.
}
node *addList(node *lista, char title[tam]){
	node *cur=lista;
	node *new=(node *) malloc(sizeof(node)); // cria novo nó.
	
	strcpy(new->title,title); // insere o nome.
	new->next = NULL;
	
	if(cur->next==NULL){
		lista->next = new; // caso a lista esteja vazia, o novo elemento será o primeiro da lista.
	}
	else{
		
		while(cur->next != NULL){ 
			cur = cur->next; // caso a lista não esteja vazia, o elemento será inserido no final da fila.
		}
		cur->next = new;
	}
	return lista; // retorna lista atualizada.
}
node *takePile(node *pile){
	node *seta = pile; 
	if(pile->next!=NULL){ // caso a pilha esteja vazia ele retorna null;
				seta = pile->next; // caso não esteja vazia, a função pega o primeiro elemeno da pilha.
				pile->next = pile->next->next; // atualiza a pilha removendo o primeiro elemento, substituindo-o pelo segundo.
				return seta; // retorna o primeiro elemento pego.
				//printf("\t\tTake :%s\n",seta->title);
	}
	else{
		return NULL;
		//printf("\t\tEMPTY\n");
	}
}
node *search(node *list, char file[tam]){
	node *cur = list;
	node *ant = cur;
	while (cur!=NULL){ // se a lista estiver vazia ou não for encontrado o arquivo, a função retorna null.
		ant=cur;
		cur=cur->next;
		if(cur!=NULL){
			if(strcmp(cur->title,file)==0) // caso não esteja vazia, o while ira rodá até o arquivo ser encontrado ou
				return ant; // a lista terminar. Nesse último caso a função retorna null. No primeiro caso a função retorna o elemento anterior ao procurado.
		}
	}
	//printf(" %p %s %s\n", ant, ant->name, cur->name);
	return NULL;
}
void Free(node *lista){
	if(lista->next!=NULL){
		node *pNode,*at;
		
		at = lista->next;
		while(at != NULL){ // a função usa um ponteiro auxiliar para pegar o próximo 
			pNode = at->next;// elemento da lista para salva-lo enquanto o anterior é liberado.
			free(at);
			at = pNode;
		}
	}
}
void delList (node *list, char name[tam]){
	int i;
	node *cur = search(list,name); // primeiro é feito uma busca pelo elemento da lista.
	if(cur == NULL) // caso não seja encontrado, a respota da função anterior será null, nesse caso não é necessário deletar nada.
		return;
	//printf("%s\n",cur->title);
	node *file_before = cur;  // caso seja encontrado o elemento, um ponteiro auxiliar o salva enquando o elemento anterior a ele é atualizado para
	node *file_search_for = cur->next; // apontar para o elemento posteior ao elemento salvo.
	cur=file_search_for->next;//cur vai para file após a procurada.
	file_before->next = cur;//file anterior à search_for aponta para a música após ela. 
	free(file_search_for);
}
void swap (node *list, char name1[tam], char name2[tam]){

	char name[tam];
	node *file_1 = search(list, name1); // é feito a busca pelos dois elementos.
	node *file_2 = search(list, name2);
	if(file_1 == NULL || file_2 == NULL) // caso um dos dois não exista na lista a função de troca não é feita.
		return;	
	file_1=file_1->next; // caso os dois existam dois ponteiros são direcionado a eles.
	file_2=file_2->next;
	strcpy(name,file_1->title); // uma string auxiliar é usada para armazenar um dos nomes enquanto ele é substituido pelo outro,
	strcpy(file_1->title,file_2->title); // assim o dois vão estar com o mesmo nome por alguns instantes, mas como o primeiro foi salvo
	strcpy(file_2->title,name);	 // o outro é atualizado com o nome salvo.
}
void show(node *list){
	node *cur=list;
	int i=1;
	system("clear");
	printf("######################################\n");
	if(cur == NULL){ // caso a lista esteja vazia...
		printf("\t\tEMPTY\n######################################\n");
		return;
	}
	printf("All list: \n");
	while(cur!=NULL){ // ler todos os elementos enquanto a lista não chega ao fim
		printf("\t\t%d:%s\n",i,cur->title);
		i++;
		cur=cur->next;
	}
	printf("######################################\n\n\n");
}
void pilha(){
	int i,j,k,l;
	node *pilha,*seta;
	char cpy[tam];
	pilha = (node*)malloc(sizeof(node));
	pilha->next = NULL;
	system("clear");
	strcpy(pilha->title,"head");
	char command[tam]={"Create by Silva L. F. M."},aux[tam],aux1[tam],choice;
	while(1){
		// menu está em inglês pois pensei no começo em treinar meu inglês, como ele ainda é básico, optei apenas por deixa-lo na execução do código.
		printf("Last Command [%s]\n",command);
		printf("###########################################################\n");		
		printf("\t\t\t >  Pile  <                       #\n                                                          #\n");
		printf("\t\t\t >Commands<                       #\n                                                          #\n");
		printf("queue \"file\"            : Add a new file in your pile     #\n");
		printf("take                      : Take the first file on pile   #\n");
		printf("swap \"file_1\" \"file_2\": You will swap the files           #\n");
		printf("take                      : Take the first file on pile   #\n");
		printf("show                      : Show all pile titles          #\n");
		printf("clear                     : clear all pile                #\n");
		printf("exit : exit for this example                              #\n");
		printf("###########################################################\n");
		printf("Create by Luis Felipe Miranda da Silva <cin.ufpe.br/~lfms\n: ");
		scanf(" %[^\n]",command);
		if(command[0] == 'q'){
			i=j=0;
			while(command[i]!= 32) i++;
			for(i++;command[i]!= '\0';i++){ // há alguns desses for's ao longo de todo o programa, usei os para pegar as palavras digitadas 
				aux[j] = command[i]; // logo após o espaço dois do comando. 32 = ' '(trinta e dois igual ao espaço na tabela ascii).
				j++;
			}
			aux[j]='\0';
			pilha = addPilha(pilha,aux);
			system("clear");

		}
		else if(command[0] == 't'){
			system("clear");
			printf("######################################\n");
			seta = takePile(pilha); 
			if(seta !=NULL){
				seta=seta->next;
				printf("%s\n",seta->title);
				printf("Edit file? y|n:\n");
				scanf(" %c",&choice);
				while(choice != 'y' && choice != 'n'){
					printf("Edit file? y|n:\n");
					scanf(" %c",&choice);
				}
				if(choice == 'y'){
					//edit(aux);
				}
			}
			else printf("Not found.\n");
			printf("######################################\n");
		}
		else if(command[0] == 's' && command[1] == 'w'){
			i=j=0;
			if(pilha->next != NULL && pilha->next->next!=NULL){
				while(command[i]!= 32) i++;
				for(i++;command[i]!= 32;i++){
					aux[j] = command[i];
					j++;
				}
				aux[j]='\0';
				j=0;
				for(i++;command[i]!= '\0';i++){
					aux1[j] = command[i];
					j++;
				}
				aux1[j]='\0';
				printf("%s %s\n",aux,aux1 );
				swap(pilha,aux,aux1);
			}
			system("clear");
		}
		else if(command[0] == 's' && command[1] == 'h'){
			show(pilha->next);
		}
		else if(command[0] == 'e' && command[1] == 'x'){
			show(pilha->next);
		}
		else if(command[0] == 'c' && command[1] == 'l'){
			Free(pilha);
			pilha = (node*)malloc(sizeof(node));
			pilha->next = NULL;
			system("clear");
		}
		else 
			system("clear");	
	}
	Free(pilha);
}
void lista_fila(){
	int i,j,k,l;
	node *list,*seta;
	list = (node*)malloc(sizeof(node));
	list->next = NULL;
	strcpy(list->title,"head");
	system("clear");
	char command[tam]={"Create by Silva L. F. M."},aux[tam],aux1[tam],choice;
	while(1){
		printf("Last Command [%s]\n",command);
		printf("###########################################################\n");
		printf("\t\t\t >List/Row<                       #\n                                                          #\n");
		printf("\t\t\t >Commands<                       #\n                                                          #\n");
		printf("add \"file\"              : add a new file in your list     #\n");
		printf("del \"file\"              : delete this file                #\n");
		printf("search \"file\"           : search for the file             #\n");
		printf("swap \"file_1\" \"file_2\"  : you will swap the files         #\n");
		printf("show                      : show all file lists titles    #\n");
		printf("clear                     : clear all pile                #\n");
		printf("exit : exit for this example                              #\n");
		printf("###########################################################\n");
		printf("Create by Luis Felipe Miranda da Silva <cin.ufpe.br/~lfms\n: ");
		scanf(" %[^\n]",command);
		if(command[0] == 'a'){
			i=j=0;
			while(command[i]!= 32) i++;
			for(i++;command[i]!= '\0';i++){
				aux[j] = command[i];
				j++;
			}
			aux[j]='\0';
			list = addList(list,aux);
			system("clear");

		}
		else if(command[0] == 'd'){
			i=j=0;
			while(command[i]!= 32) i++;
			for(i++;command[i]!= '\0';i++){
				aux[j] = command[i];
				j++;
			}
			aux[j]='\0';
			delList(list,aux);
			system("clear");

		}
		else if(command[0] == 's' && command[1] == 'e'){
			i=j=0;
			while(command[i]!= 32) i++;
			for(i++;command[i]!= '\0';i++){
				aux[j] = command[i];
				j++;
			}
			aux[j]='\0';
			seta=search(list,aux);
			if(seta !=NULL){
				seta=seta->next;
				printf("%s\n",seta->title);
				printf("Edit file? y|n:\n");
				scanf(" %c",&choice);
				while(choice != 'y' && choice != 'n'){
					printf("Edit file? y|n:\n");
					scanf(" %c",&choice);
				}
				if(choice == 'y'){
					//edit(aux);
				}
				printf("Delete file? y|n:\n");
				scanf(" %c",&choice);
				while(choice != 'y' && choice != 'n'){
					printf("Edit file? y|n:\n");
					scanf(" %c",&choice);
				}
				if(choice == 'y'){
					delList(list,aux);
				}
			}
			else printf("Not found.\n");
			system("clear");
		}
		else if(command[0] == 's' && command[1] == 'w'){
			i=j=0;
			while(command[i]!= 32) i++;
			for(i++;command[i]!= 32;i++){
				aux[j] = command[i];
				j++;
			}
			aux[j]='\0';
			j=0;
			for(i++;command[i]!= '\0';i++){
				aux1[j] = command[i];
				j++;
			}
			aux1[j]='\0';
			printf("%s %s\n",aux,aux1 );
			swap(list,aux,aux1);
			system("clear");
		}
		else if(command[0] == 's' && command[1] == 'h'){
			show(list->next);
		}
		else if(command[0] == 'e' && command[1] == 'x'){
			return;
		}
		else if(command[0] == 'c' && command[1] == 'l'){
			Free(list);
			list = (node*)malloc(sizeof(node));
			list->next = NULL;
			system("clear");
		}
		else
			system("clear");
	}
	Free(list);
}
int main(){
	lista_fila();
	pilha();
	bye();
}