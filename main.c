#include <stdio.h>
#include <pthread.h>

void* run(void* data)
{
    // This is the function that will be run by the thread.
    size_t thread_num = (size_t)data;

    // Second thread will print its number
    printf("Hello world from secondary thread %zu\n", thread_num);

    // Return NULL to indicate that the thread has finished.
    return NULL;
}

int main(void)
{
    // Declare a thread
    pthread_t thread;

    // Create a thread
    pthread_create(&thread, NULL, run, (void*)13);

    // Main thread prints a message
    printf("Hello world from main thread\n");

    // Main thread waits for the second thread to finish
    pthread_join(thread, NULL);

    return 0;
}
