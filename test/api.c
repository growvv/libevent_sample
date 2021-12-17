#include<stdio.h>
#include<event2/event.h>

int main() {

    // libevent version
    printf("LIBEVENT_VERSION_NUMBER:%d\n", LIBEVENT_VERSION_NUMBER);
    printf("version: %s\n", event_get_version());
    struct event_base *base;
    base = event_base_new();
    // return current the method of multi-thread io
    const char *x =  event_base_get_method(base);
    printf("METHOD:%s\n", x);

    // return base support bit mask
    int t = event_base_get_features(base);
    if(t & EV_FEATURE_ET) {  // 支持边沿触发的后端
        printf("EV_FEATURE_ET\n");
    } 
    if(t & EV_FEATURE_O1) {  // 添加、删除单个事件，或者确定哪个事件激活的操作是 O（1）复杂度的后端
        printf("EV_FEATURE_O1\n");
    }
    if(t & EV_FEATURE_FDS) {  // /要求支持任意文件描述符，而不仅仅是套接字的后端
        printf("EV_FEATURE_FDS\n");
    }
 

    int y = event_base_dispatch(base);
    event_base_free(base);
    return 1;
}