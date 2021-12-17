# libevent_sample
The basic sample of libevent


### 1. chat-server

libevent的基本使用样例

将socket设置为非阻塞，这在使用libevent进行基于事件的编程时非常重要。

然后设置了on_accept回调，on_accept中又设置了on_read回调

这样当有新的连接进来时，就会触发on_accept，然后当socket读就绪时触发on_read

### 2. echo_back1

和1的功能一样，只是使用的接口不一样

用 `bufferevent_new` 代替了 `bufferevent_socket_new` 和 `bufferevent_setcb`

### 3. echo_back2

加入了“线程池”，在on_accept中将新连接client添加到线程池的任务队列中，

每个client自己设置on_read回调，并执行`event_base_dispatch` 事件循环，管理就绪事件

缺点：每个client会占用一个线程（阻塞），直到连接关闭。当连接数超过线程数时，新连接不会被处理。

### 4. echo_back3

在3之上改进，主线程负责on_accept和on_read回调，在on_read中将job添加到线程池的任务队列中，

线程能很快处理完一个读就绪，不会被某个连接长期占用

优点：每个请求都能被及时处理，CPU利用率提高，整体吞吐量提高

缺点：回调函数（handle）不能阻塞；回调地狱；异步编程

可以用协程，去掉回调函数，用同步的方式编程