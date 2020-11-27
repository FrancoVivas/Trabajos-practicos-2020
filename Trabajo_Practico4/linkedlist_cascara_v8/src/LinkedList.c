#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this;
    this= (LinkedList *)malloc(sizeof(LinkedList));
    if(this != NULL)
    {
        this->size= 0;
        this->pFirstNode= NULL;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux= -1;
    if(this != NULL)
    {
        returnAux= this->size;
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    int i;
    int tam;
    Node* pNode = NULL;

    if(this != NULL)
    {
        tam= ll_len(this);
        if(this!= NULL && nodeIndex>=0 && nodeIndex<tam)
        {
            pNode= this->pFirstNode;
            for(i=0; i<nodeIndex; i++)
            {
                pNode= pNode->pNextNode;
            }
        }
    }
    return NULL;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux= -1;
    int tam;

    Node* pNewNode= malloc(sizeof(Node));
    Node* pActualNode= NULL;
    pNewNode->pElement=pElement;

    if(this!= NULL && pNewNode!= NULL)
    {
        tam= ll_len(this);
        if(nodeIndex>=0 && nodeIndex<= tam)
        {
            if(nodeIndex==0)
            {
                pNewNode->pNextNode= this->pFirstNode;
                this->pFirstNode= pNewNode;
            }
            else
            {
                pActualNode= getNode(this,nodeIndex-1);
                pNewNode->pNextNode= pActualNode->pNextNode;
                pActualNode->pNextNode= pNewNode;
            }
            returnAux= 0;
            this->size++;
        }
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux= -1;
    if(this != NULL)
    {
        returnAux= addNode(this, this->size, pElement);
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    int tam;
    void* returnAux = NULL;
    Node* pNewNode;

    if(this != NULL)
    {
        tam= ll_len(this);
        if(index>=0 && index<tam)
        {
            pNewNode= getNode(this, index);
            if(pNewNode != NULL)
            {
                returnAux= pNewNode->pElement;
            }
        }
    }
    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int tam;
    int returnAux= -1;
    Node* pNewNode;

    if(this != NULL)
    {
        tam= ll_len(this);
        if(index>=0 && index<tam)
        {
            pNewNode= getNode(this, index);
            if(pNewNode != NULL)
            {
                pNewNode->pElement= pElement;
                returnAux= 0;
            }
        }
    }
    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux= -1;

    Node *pNodeUno;
    Node *pNodeDos;

    if(this!= NULL)
    {
        if(index>=0 && index<this->size)
        {
            returnAux= 0;
            if(this->size == 1)
            {
                this->pFirstNode= NULL;
                free(getNode(this,index));
            }
            else if(index == 0)
            {
                pNodeUno= getNode(this,index);
                this->pFirstNode= pNodeUno->pNextNode;
                free(pNodeUno);
            }
            else
            {
                pNodeUno= getNode(this,index);
                if(pNodeUno != NULL)
                {
                    pNodeDos= getNode(this,index-1);
                    pNodeDos->pNextNode= pNodeUno->pNextNode;
                    free(pNodeUno);
                }
            }
        }
        this->size--;
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int i;
    int tam;
    int returnAux= -1;

    if(this != NULL)
    {
        tam= ll_len(this);
        for(i=0; i<tam; i++)
        {
            ll_remove(this,i);
        }
        returnAux= 0;
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux= -1;
    if(this != NULL)
    {
        if(ll_clear(this) == 0)
        {
            free(this);
            returnAux= 0;
        }
    }
    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int i;
    int tam;
    int returnAux= -1;

    Node* pNode= NULL;

    if(this != NULL)
    {
        tam= ll_len(this);
        for(i=0; i<tam; i++)
        {
            pNode= getNode(this,i);
            if(pNode->pElement == pElement)
            {
                returnAux= i;
                break;
            }
        }
    }
    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int tam;
    int returnAux= -1;

    if(this != NULL)
    {
        tam= ll_len(this);
        if(tam == 0)
        {
            returnAux= 1;
        }
        else
        {
            returnAux= 0;
        }
    }
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux= -1;
    int tam;

    if(this != NULL)
    {
        tam= ll_len(this);
        if(index>=0 && index<=tam)
        {
            returnAux= addNode(this, index, pElement);
        }
    }
    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux= NULL;
    int tam;

    if(this != NULL)
    {
        tam= ll_len(this);
        if(index>=0 && index<=tam)
        {
            returnAux= ll_get(this, index);
            ll_remove(this, index);
        }
    }
    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux= -1;
    if(this != NULL)
    {
        if (ll_indexOf(this, pElement) == -1)
        {
            returnAux= 0;
        }
        else
        {
            returnAux= 1;
        }
    }
    return returnAux;
}


/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this, LinkedList* this2)
{
    int i;
    int lenUno;
    int lenDos;
    int returnAux= -1;
    int contador= 0;

    void* pElementAux;

    if(this!=NULL && this2!=NULL)
    {
        lenUno= ll_len(this);
        lenDos= ll_len(this2);

        returnAux=0;

        if(lenUno >= lenDos)
        {
            for(i=0 ; i<lenDos; i++)
            {
                pElementAux= ll_get(this2, i);
                if(ll_contains(this, pElementAux) == 1)
                {
                    contador++;
                }
            }
            if(contador==lenUno)
            {
                returnAux= 1;
            }
        }
    }
    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    int i;
    int tam;
    int nuevaLista= 0;

    Node* pNode;
    LinkedList* cloneArray= NULL;

    if(this != NULL)
    {
        tam= ll_len(this);
        if(from>=0 && from<=tam && to>=0 && to<=tam)
        {
            cloneArray= ll_newLinkedList();
            for(i=from; i<to; i++)
            {
                pNode= getNode(this, i);
                if(pNode != NULL)
                {
                    addNode(cloneArray, nuevaLista, pNode->pElement);
                    nuevaLista++;
                }
            }
        }
    }
    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray= NULL;
    if(this != NULL)
    {
        cloneArray= ll_subList(this, 0, this->size);
    }
    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */

int ll_sort(LinkedList* this, int (*pFunc)(void*,void*), int order)
{
    int i;
    int tam;
    int flag;
    int returnAux= -1;

    void* pElementA;
    void* pElementB;
    void* pElementAux;

    if(this != NULL)
    {
        if(pFunc != NULL)
        {
            if(order==0 || order==1)
            {
                tam= ll_len(this);
                if(tam > 0)
                {
                    do
                    {
                        flag= 0;
                        for(i=0; i<tam-1; i++)
                        {
                            pElementA= ll_get(this,i);
                            pElementB= ll_get(this,i+1);
                            if((pFunc(pElementA, pElementB) <0 && order==0) || (pFunc(pElementA, pElementB) >0 && order==1))
                            {
                                pElementAux= pElementA;
                                ll_set(this,i,pElementB);
                                ll_set(this,i+1,pElementAux);
                                flag= 1;
                            }
                            returnAux= 0;
                        }
                    }while(flag);
                }
            }
        }
    }
    return returnAux;
}

