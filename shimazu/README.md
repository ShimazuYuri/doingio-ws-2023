# doingio-ws-2023
東京藝術大学芸術情報センター 夏季WS D+IOワークショップ  

## 材料
- arduino uno 1個
- USBケーブル1本
- 圧電スピーカー 1個
- 静電容量式タッチセンサー(TTP223) 5個 
- ピンヘッダ(1×3) 2個
- 圧力センサー(fsr402) 1個
- ブレッドボード 1個
- ジャンパー線 適量
- ワニグリップ付きジャンパー線 2本
- はんだ 適量
- アクリル板A4サイズ(任意) 1枚
- テープ 適量

## 使用機材
- はんだごて
- レーザーカッター(任意)(アクリル板のカットに使用)

## 作り方
### 準備
タッチセンサー3つに、ジャンパー線を3本ずつ半田付けする。

残りのタッチセンサー2つに、ピンヘッダを半田付けする。

アクリル板(任意)をsvgファイルのようにカットしておく。

### 接続
CAD画像の通りに接続する。

圧電スピーカーとarduino uno,ブレッドボードの接続にはワニグリップ付きジャンパー線を使用する。

![CAD画像.png](https://github.com/ShimazuYuri/doingio-ws-2023/blob/main/shimazu/CAD%E7%94%BB%E5%83%8F.png)

アクリル板を使用する場合は、図のように取り付ける。
![アクリル板.png](https://github.com/ShimazuYuri/doingio-ws-2023/blob/main/shimazu/%E3%82%A2%E3%82%AF%E3%83%AA%E3%83%AB%E6%9D%BF.png)

### arduino ide
PCとarduino unoを接続する。
arduino ideで9.22.inoを読み込み、アップロードする。
## 操作方法

右手の人差し指、中指、薬指で右上の2つのセンサーを操作する。

左手でブレッドボード上のタッチセンサーを操作する。

運指表
![シ♭.png](https://github.com/ShimazuYuri/doingio-ws-2023/blob/main/shimazu/%E3%82%B7%E2%99%AD.png)

## 主な動作
センサーをタッチしたまま圧力センサーに力をかけると、音が出る。

