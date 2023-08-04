# rp2040_6key_pad_example

## 動作
- USBシリアル変換アダプタとして機能し、PCのシリアルポートへ押されたキーの番号を文字列で送信します
- 例えばSW1を押したら"Button0 Pressed"がPCへ送信されます
- 押されたキーに応じて、LEDを点灯させます



## ビルド方法
rapsberrypi pico sdkが必要ですので下記URLに従ってインストールしてください。

https://github.com/raspberrypi/pico-sdk

インストールが完了したら、下記コマンドで.uf2ファイルが生成されます。
```
mkdir build
cd build
cmake .. -DPICO_SDK_PATH=<raspberrypi picoのSDKが保存されいるディレクトリを指定する>
make
```

