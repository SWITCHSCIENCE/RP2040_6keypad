# RP2040_6keypad

This repository contains KiCad data for 6keypads using the Switch Science RP2040 breakout board.

## sample_software/rp2040_6key_pad_example

Raspberry Pi Pico C/C++ SDKを用いた簡単なサンプルソフトウェアです。USBシリアル変換アダプターとして機能し、押されたキーの番号をPCのシリアルポートへ送信します。
さらに押されたキーに対応するLEDが点灯します。簡単なREADME.mdを添付しています。

## qmk_firmware/qmk_configs_for_rp2040_6_keypad

QMK Firmwareをrp2040 6-key padに対応させるための設定ファイルとソースコードを書きました。ソースコード差分のみzipファイルにしています。
ビルド方法などの詳細は中のREADME.mdをご確認ください。
今回は6つのキーをBackspace、Enter、上下左右キーに割り振っています。LEDはCapsLockのLEDインジケーターとして動作します。

## prk_firmware/keymap.rb

PRK Firmware用のキーボード設定ファイルです。[PRK Firmware](https://github.com/picoruby/prk_firmware)のuf2ファイルを書き込み後、このファイルkeymap.rbをコピーしてください。
