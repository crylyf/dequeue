#include <stdlib.h>
#include <assert.h>
// a Double Ended Queue for ints
// NOTE: ALL double ended queue parameters must be valid

#include <stdio.h>
#include <stdbool.h>

// DO NOT MODIFY THIS STRUCTURE
struct dllnode {
  int item;
  struct dllnode *prev;
  struct dllnode *next;
};

// DO NOT MODIFY THIS STRUCTURE
struct dequeue {
  struct dllnode *front;
  struct dllnode *back;
};


struct dequeue *dequeue_create(void) {
  struct dequeue *q = malloc(sizeof(struct dequeue));
  q->back = NULL; 
  q->front = NULL;
  return q;
}




bool dequeue_is_empty(const struct dequeue *q) {
  return q->front == NULL;
}




int dequeue_front(const struct dequeue *q) {
  assert(q->front != NULL);
  return q->front->item;
}




int dequeue_back(const struct dequeue *q) {
assert (q->back != NULL); 
return q->back->item;}



int dequeue_remove_front(struct dequeue *q) {
  int i = q->front->item;
  struct dllnode *temp = q->front;
  q->front = q->front->next;
  free(temp);
  if(q->front == NULL){
    q->back = NULL;
    return i;
  }

    return i;
  }





int dequeue_remove_back(struct dequeue *q) {
  assert(q);
  int i = q->back->item;
  struct dllnode *temp = q->back;
  q->back = q->back->next;
  free(temp);
  if(q->back == NULL){
    q->front = NULL;
  }

    return i;
  
}




void dequeue_add_front(int item, struct dequeue *q) {
  struct dllnode *temp = malloc (sizeof(struct dllnode));
  temp->item = item;
  temp->next = NULL;
  
  if(q->back == NULL){
    q->back = temp;
    //q->back = temp;
  }
  else{
    q->front->next = q->front;
    temp->next = q->front;
temp->next = q->front;  }
  q->front = temp;
}







void dequeue_add_back(int item, struct dequeue *q){
  struct dllnode *temp = malloc(sizeof(struct dllnode));
  temp->item = item;
  temp->next = NULL;
  temp->prev = q->back;
  
  if(!q->front && !q->back){
    q->back = temp;
    q->front = temp;
    return;
  }
    q->back->next = temp;
    q->back = temp;
  }








void dequeue_destroy(struct dequeue *q) {
  while(!dequeue_is_empty(q)){
    dequeue_remove_front(q);
  }
  free(q);
}

// DO NOT MODIFY THIS FUNCTION
// dequeue_print(q) prints the contents of q
// effects: prints to output
void dequeue_print(const struct dequeue *q) {
  struct dllnode *temp = q->front;
  
  printf("Dequeue:\n");
  printf("Front -> ");
  while (temp) {
    printf("%d -> ", temp->item);
    temp = temp->next;
  }
  printf("NULL\n");
  
  temp = q->back;
  printf("Back -> ");
  while (temp) {
    printf("%d -> ", temp->item);
    temp = temp->prev;
  }
  printf("NULL\n");
}

