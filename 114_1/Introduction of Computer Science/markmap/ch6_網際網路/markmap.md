---
title: aaa
markmap:
  colorFreezeLevel: 2
---


### 2. 資料連接層 data link layer
### 3. 網路層 network layer

#### 功能
##### 網路位址 addressing 
- IP 位址 (傳統、私有)
- 網路識別碼 (network id)
- 網路遮罩 (netmask)
##### 資料分割組裝 (de)fragmentation
- 資料傳輸是以封包 (packet) 為單位
- 每一個封包裡除了存放傳輸內容外，還需要加上標頭 (header)
##### 網路路由 routing
- 網路封包由網路主機送出後，便由路由器 (router) 負責傳送
- 倚靠路徑演算法 (routing algorithm) ，計算由發送端至目的端的最佳路徑
- 路由器之間透過路由協定 (routing protocol) 來交換彼此之間的網路狀態
#### 協定
- IPv4
  - 32-bit or 4x8-bit
- IPv6
  - 128-bit or 8x16-bit


### 4. 傳輸層 transport layer

#### 多工 multiplexing
#### 流量控制 flow control
#### 壅塞控制 congestion control

#### 協定 
##### TCP (Transmission Control Protocol)
- 屬於連接導向 connection-oriented
- 三方交握 (three-way handshaking)
- 可靠
##### UDP (User Datagram Protocol)
- 屬於無連接導向 connectionless