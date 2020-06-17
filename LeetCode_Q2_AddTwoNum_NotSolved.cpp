#include <iostream>  //////////////////not done yet
#include <vector>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };

int main(){
    ListNode *l1,*l2, *temp1, *temp2;

    l1 = new ListNode(5);
    temp1 = new ListNode(4);
    l1->next = temp1;
    temp2 = new ListNode(3);
    temp1->next = temp2;
    temp1 = new ListNode(NULL);
    temp2->next = temp1;

    l2 = new ListNode(5);
    temp1 = new ListNode(6);
    l2->next = temp1;
    temp2 = new ListNode(4);
    temp1->next = temp2;
    temp1 = new ListNode(NULL);
    temp2->next = temp1;

    ListNode *answer;
    answer = new ListNode(NULL);
    ListNode *rear;
    rear = new ListNode(NULL);
    answer->next = rear;
    int rem=0;

    ListNode *p1,*p2;
    p1 = l1;
    p2 = l2;
    while (p1->val!=NULL || p2->val!=NULL){
        int num1, num2,sum;
        if(p1->val==NULL){
            num1 = 0;
        }else{
            num1 = p1->val; 
        }
        if(p2->val==NULL){
            num2 = 0;
        }else{
            num2 = p2->val; 
        }
        sum = num1 + num2 + rem;
        cout << sum <<endl;
        if(sum < 10){
            if (answer->val == NULL){
                answer->val = sum;
            }else{
                rear->val = sum;
                cout << 'a'<<answer->next->val <<endl;
                ListNode *temp3;
                temp3 = new ListNode(NULL);
                rear->next = temp3;
                rear = temp3;
            }
            rem = 0;
        }else{
            if (answer->val == NULL){
                answer->val = sum-10;
            }else{
                rear->val = sum-10;
                cout << 'b'<<answer->next->val <<endl;
                ListNode *temp3;
                temp3 = new ListNode(NULL);
                rear->next = temp3;
                rear = temp3;
            }
            rem = 1;    
        }  
        if (p1->val == NULL && p2->val != NULL){
            p2 = p2->next;
        }else if(p1->val != NULL && p2->val == NULL){
            p1 = p1->next;
        }else{
            p1 = p1->next;
            p2 = p2->next;
        } 


    }
    
    ListNode *p3;
    p3 = answer;
    while (p3->val!=NULL){
        cout << p3->val << ' ';
        p3 = p3->next;
    }
}
