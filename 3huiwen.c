#include <stdio.h>

#define N 100

typedef struct stackStruct
{
    char stackData[N];  // ջ����
    int top;            // ջ������
} Stack;

typedef struct queueStruct
{
    char queueData[N];  // ��������
    int rear, front;    // ��β�Ͷ�ͷ����
} Queue;

int check(Stack, Queue);

int main(void)
{
    int answer, i = 0;
    char s[N];
    Stack stack;
    Queue queue;
    queue.rear = -1;  // ��ʼ������
    scanf("%s", s);  // �����ַ���
    for (; s[i] != '#'; i++)
    {
        stack.stackData[i] = s[i];  // ���ַ�����ѹ��ջ�Ͷ���
        queue.queueData[i] = s[i];
    }
    queue.front = stack.top = i;  // ���ö�ͷ��ջ������
    answer = check(stack, queue);  // ����Ƿ�Ϊ�����ַ���
    if (answer == 1)
        printf("It's a Palindromic string.\n ");
    else
        printf("It isn't a Palindromic string.\n ");
    return 0;
}

int check(Stack stack, Queue queue)
{
    int flag = 1;  // �ȼٶ��ǻ����ַ���

    while (stack.top != 0)
    {
        stack.top--, queue.rear++;  // ��ջ�ͳ�����
        if (stack.stackData[stack.top] != queue.queueData[queue.rear])
        {
            flag = 0;  // ���ǻ����ַ���
            break;
        }
    }
    return flag;
}
