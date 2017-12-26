#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

pthread_key_t key;

typedef struct test_struct
{
    int i;
    float k;
}TestStruct;

void *func(void *arg)
{
    TestStruct tData;
    tData.i = 10;
    tData.k = 3.1415;
    pthread_setspecific(key,&tData);
    printf("func tData local = 0x%p\n",&(tData));
    printf("func getspecific = 0x%p\n",(TestStruct *)pthread_getspecific(key));
    printf("func TestStruct.i = %d ; TestStruct.k = %f\n",((TestStruct*)pthread_getspecific(key))->i,((TestStruct*)pthread_getspecific(key))->k);
    int b;
    b = 111;
    pthread_setspecific(key,&b);
    printf("func %d\n",*((int*)pthread_getspecific(key)));
}

void *func1(void *arg)
{
    int temp = 20;
    sleep(2);
    printf("func1 temp = 0x%p\n",&temp);
    pthread_setspecific(key,&temp);
    printf("func1 getspecific = 0x%p\n",(int*)pthread_getspecific(key));
}

int main()
{
    pthread_t tid1,tid2;
    pthread_key_create(&key,NULL);
    pthread_create(&tid1,NULL,(void*)func,NULL);
    pthread_create(&tid2,NULL,(void*)func1,NULL);
    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);
    pthread_key_delete(key);
    return 0;
}
