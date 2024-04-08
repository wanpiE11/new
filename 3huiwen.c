#include <stdio.h>

#define N 100

typedef struct stackStruct
{
    char stackData[N];  // 栈数据
    int top;            // 栈顶索引
} Stack;

typedef struct queueStruct
{
    char queueData[N];  // 队列数据
    int rear, front;    // 队尾和队头索引
} Queue;

int check(Stack, Queue);

int main(void)
{
    int answer, i = 0;
    char s[N];
    Stack stack;
    Queue queue;
    queue.rear = -1;  // 初始化队列
    scanf("%s", s);  // 输入字符串
    for (; s[i] != '#'; i++)
    {
        stack.stackData[i] = s[i];  // 将字符依次压入栈和队列
        queue.queueData[i] = s[i];
    }
    queue.front = stack.top = i;  // 设置队头和栈顶索引
    answer = check(stack, queue);  // 检查是否为回文字符串
    if (answer == 1)
        printf("It's a Palindromic string.\n ");
    else
        printf("It isn't a Palindromic string.\n ");
    return 0;
}

int check(Stack stack, Queue queue)
{
    int flag = 1;  // 先假定是回文字符串

    while (stack.top != 0)
    {
        stack.top--, queue.rear++;  // 出栈和出队列
        if (stack.stackData[stack.top] != queue.queueData[queue.rear])
        {
            flag = 0;  // 不是回文字符串
            break;
        }
    }
    return flag;
}
