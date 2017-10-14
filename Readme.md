# Subscribing to many things issue

This is the ESP MQTT example code, with the lights stripped out and stuff added to the connect success block.

Subscribe to a bunch of topics, none of which give responses, subscriptions 1-6 are fast, 7-10 are really slow, the rest are fast.

The numbers are different if the topics return responses, 1-3 is fast, 4-6 are slow, the rest are fast, but then the client gets disconnected from the mqtt broker for being idle.

## topics return nothing

works, slowly.

```
Attempting MQTT connection...connected
Subscribing
1323
FOOBAR/stat/i3/commons/lights/scuzzLights001/POWER
1323
FOOBAR/stat/i3/commons/lights/scuzzLights002/POWER
1371
FOOBAR/stat/i3/commons/lights/scuzzLights003/POWER
1377
FOOBAR/stat/i3/commons/lights/scuzzLights004/POWER
1391
FOOBAR/stat/i3/commons/lights/scuzzLights005/POWER
1399
FOOBAR/stat/i3/commons/lights/scuzzLights006/POWER
1414
FOOBAR/stat/i3/commons/lights/scuzzLights007/POWER
6416
FOOBAR/stat/i3/commons/lights/scuzzLights008/POWER
16418
FOOBAR/stat/i3/commons/lights/scuzzLights009/POWER
21421
FOOBAR/stat/i3/commons/lights/scuzzLights010/POWER
21427
FOOBAR/stat/i3/commons/lights/scuzzLights011/POWER
21433
FOOBAR/stat/i3/commons/lights/scuzzLights012/POWER
21441
FOOBAR/stat/i3/commons/lights/scuzzLights013/POWER
21445
FOOBAR/stat/i3/commons/lights/scuzzLights014/POWER
21449
FOOBAR/stat/i3/commons/lights/scuzzLights015/POWER
21456
FOOBAR/stat/i3/commons/lights/scuzzLights016/POWER
21462
FOOBAR/stat/i3/commons/lights/scuzzLights017/POWER
21471
FOOBAR/stat/i3/commons/lights/scuzzLights018/POWER
21475
FOOBAR/stat/i3/commons/lights/scuzzLights019/POWER
21498
FOOBAR/stat/i3/commons/lights/scuzzLights020/POWER
21507
FOOBAR/stat/i3/commons/lights/scuzzLights021/POWER
21522
FOOBAR/stat/i3/commons/lights/scuzzLights022/POWER
21530
FOOBAR/stat/i3/commons/lights/scuzzLights023/POWER
21539
FOOBAR/stat/i3/commons/lights/scuzzLights024/POWER
21547
FOOBAR/stat/i3/commons/lights/scuzzLights025/POWER
21554
FOOBAR/stat/i3/commons/lights/scuzzLights026/POWER
21560
FOOBAR/stat/i3/commons/lights/scuzzLights027/POWER
21568
FOOBAR/stat/i3/commons/lights/scuzzLights028/POWER
21577
FOOBAR/stat/i3/commons/lights/scuzzLights029/POWER
21592
FOOBAR/stat/i3/commons/lights/scuzzLights030/POWER
21598
FOOBAR/stat/i3/commons/lights/scuzzLights031/POWER
21606
FOOBAR/stat/i3/commons/lights/scuzzLights032/POWER
21614
FOOBAR/stat/i3/commons/lights/scuzzLights033/POWER
21624
FOOBAR/stat/i3/commons/lights/scuzzLights034/POWER
21633
```
## topics return stuff

Gets kicked from broker for idle

```
IP address:
10.13.0.202
Attempting MQTT connection...connected
Subscribing
2232
stat/i3/commons/lights/scuzzLights001/POWER
2232
stat/i3/commons/lights/scuzzLights002/POWER
2286
stat/i3/commons/lights/scuzzLights003/POWER
2295
Message arrived [tele/i3/commons/lights/scuzzLights001/LWT] Online
stat/i3/commons/lights/scuzzLights004/POWER
12298
stat/i3/commons/lights/scuzzLights005/POWER
32300
stat/i3/commons/lights/scuzzLights006/POWER
38740
Message arrived [tele/i3/commons/lights/scuzzLights002/LWT] Online
stat/i3/commons/lights/scuzzLights007/POWER
38743
Message arrived [stat/i3/commons/lights/scuzzLights001/POWER] ON
stat/i3/commons/lights/scuzzLights008/POWER
38754
stat/i3/commons/lights/scuzzLights009/POWER
38758
stat/i3/commons/lights/scuzzLights010/POWER
38763
stat/i3/commons/lights/scuzzLights011/POWER
38767
stat/i3/commons/lights/scuzzLights012/POWER
38772
stat/i3/commons/lights/scuzzLights013/POWER
38776
stat/i3/commons/lights/scuzzLights014/POWER
38781
stat/i3/commons/lights/scuzzLights015/POWER
38785
stat/i3/commons/lights/scuzzLights016/POWER
38790
stat/i3/commons/lights/scuzzLights017/POWER
38794
stat/i3/commons/lights/scuzzLights018/POWER
38799
stat/i3/commons/lights/scuzzLights019/POWER
38803
stat/i3/commons/lights/scuzzLights020/POWER
38808
stat/i3/commons/lights/scuzzLights021/POWER
38812
stat/i3/commons/lights/scuzzLights022/POWER
38817
stat/i3/commons/lights/scuzzLights023/POWER
38821
stat/i3/commons/lights/scuzzLights024/POWER
38826
stat/i3/commons/lights/scuzzLights025/POWER
38830
stat/i3/commons/lights/scuzzLights026/POWER
38835
stat/i3/commons/lights/scuzzLights027/POWER
38839
stat/i3/commons/lights/scuzzLights028/POWER
38844
stat/i3/commons/lights/scuzzLights029/POWER
38848
stat/i3/commons/lights/scuzzLights030/POWER
38853
stat/i3/commons/lights/scuzzLights031/POWER
38857
stat/i3/commons/lights/scuzzLights032/POWER
38862
stat/i3/commons/lights/scuzzLights033/POWER
38866
stat/i3/commons/lights/scuzzLights034/POWER
38871
Attempting MQTT connection...connected
Subscribing
39723
stat/i3/commons/lights/scuzzLights001/POWER
39723
stat/i3/commons/lights/scuzzLights002/POWER
39770
stat/i3/commons/lights/scuzzLights003/POWER
39776
```
### mosquitto mqtt broker logs
```
1507944621: New client connected from 10.13.0.202 as ESP8266Client (c1, k15).
1507944658: Client ESP8266Client has exceeded timeout, disconnecting.
```
