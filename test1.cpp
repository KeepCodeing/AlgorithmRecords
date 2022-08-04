#include<string.h>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
int run_i = 0,run_over = 0,time_runing = 0;
struct PCB {
	char *name;
	int arrive;
	int need;
	int runtime;
	int priority;
	int endtime;
	int turn;
	char state;
	struct PCB *next;
};
int run_sum = 0;
void Init(struct PCB *head,  char *name,  int arrive,  int need,  int priority) {
	struct PCB *temp = new PCB();
	temp->name = (char *) malloc(sizeof(char) * strlen(name));
	strcpy(temp->name,name);
	temp->arrive = arrive;
	temp->need = need;
	temp->runtime = need;
	temp->priority = priority;
	temp->state = 'W';
	temp->next = head->next;
	head ->next = temp;
	return ;
}
void Add_(struct PCB *head_temp,struct PCB *head_queue) {
	struct PCB *temp = new PCB();
	temp->name = (char*)malloc(sizeof(char) * strlen(head_temp->name));
	strcpy(temp->name,head_temp->name);
	temp->arrive = head_temp->arrive;
	temp->need = head_temp->need;
	temp->runtime = head_temp->runtime;
	temp->priority = head_temp->priority;
	temp->state = 'W';
	struct PCB *p = NULL;
	for(p = head_queue; p ->next; p = p->next);
	p->next = temp;
	return;
}

void Sort_body(struct PCB *q, struct PCB *head_queue, struct PCB *h) {
	for(q = head_queue; q ->next; q = q ->next) {
		if(q->next->priority < h->priority) {
			h->next = q->next;
			q ->next = h;
			break;
		}
		if(q ->next->priority == h ->priority) {
			if(q->next->arrive > h->arrive) {
				h->next = q->next;
				q ->next = h;
				break;
			}
		}
	}
}



void Sort(struct PCB *head_queue) {
	struct PCB *p = head_queue ->next;
	struct PCB *q = NULL;
	(head_queue) ->next = NULL;
	for(struct PCB *h = p; p; ) {
		h = p;
		p = p ->next;
		h ->next = NULL;
		Sort_body(q, p, h);
		if(!q ->next)
			q ->next = h;
	}
	return;
}

void Free(struct PCB *head_queue) {
	if(!(head_queue ->next))
		return;
	head_queue ->next->state = 'F';
	// Print(head_queue ->next);
	struct PCB *p = head_queue ->next;
	head_queue->next = p->next;
	delete p;
	return;
}
void display(struct PCB *head) {
	printf("======================");
	printf("\nThe processes in ready state£º\n");
	for(struct PCB *p = head ->next->next; p; p = p->next)
		if(p->state=='W')
			printf("%s ",p->name);
	printf("\n");
	printf("\nThe processes in execution state £º\n");
	PCB *p = head ->next;
	printf("%s ",p->name);
	printf("\n======================\n");
}
void check_1(struct PCB* head_queue) {
	if(run_i == 1 && head_queue->next->runtime) {
		if(head_queue->next->priority) {
			head_queue->state='R';
			head_queue->next->priority -= 1;
			if(head_queue->next->priority < 0)
				head_queue->next->priority = 0;
		}
		Sort(head_queue);
		run_i = 0;
	}
}
void check_2(struct PCB* head_queue) {
	if(!head_queue->next->runtime) {
		head_queue->state='F';
		if(head_queue->next->priority) {
			head_queue->next->priority -= 1;
			if(head_queue->next->priority < 0)
				head_queue->next->priority = 0;
		}
		head_queue->next->turn=time_runing-head_queue->next->arrive;
		Free(head_queue);
		Sort(head_queue);
		run_i = 0;
		run_over++;
	}
}

void check_3(struct PCB* head_queue, struct PCB* h, struct PCB *head) {
	if(head_queue ->next) {
		check_1(head_queue);

		check_2(head_queue);
		if(head_queue ->next)
			head_queue->next->runtime--;
		if(run_over == run_sum)
			return;
		if(run_over==run_sum-1) {

			printf("\nTime %d status of each process is shown as follows£º\n",time_runing);
			printf("======================");
			printf("\nProcess without ready state\n");

			printf("\nThe process in the execution state has£º\n");
			PCB *p = head ->next;
			printf("%s ",p->name);
			printf("\n");
		} else {
			printf("\nTime %d status of each process is shown as follows£º\n",time_runing);
			display(h);
		}
		run_i++;
	}
}
void pailie(struct PCB *head,struct PCB *head_queue) {
	struct PCB* h;
	while(time_runing >= 0) {
		h=head_queue;
		for(struct PCB *p = head ->next; p; p = p->next)
			if(time_runing == p->arrive)
				Add_(p,head_queue);
		check_3(head_queue, h, head);
		time_runing++;
		if(run_over == run_sum)
			return;
	}
	return;
}

void Print_end(struct PCB *temp) {
	printf("\nThe process has ended");
	printf("Process name:%s  \t Turnaround time :%d\n",temp->name,temp->turn);
}

int main() {
	struct PCB *head = new PCB();
	struct PCB *head_queue = new PCB();
	char name[20];
	int arrive,need,priority;
	int num;
	printf("Please enter the number of processes :\n");
	scanf("%d",&num);
	run_sum=num;
	printf("Please input process information, (process name, arrival time, service time priority)\n");
	while( num--) {
		scanf("%s%d%d%d",name,&arrive,&need,&priority);
		Init(head,name,arrive,need,priority);
	}
	pailie(head,head_queue);
}

