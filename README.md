# RP2040_6keypad

This repository contains KiCad data for 6keypads using the Switch Science RP2040 breakout board.

[Picossci RP2040 ピッチ変換基板](https://ssci.to/8440)を利用したKiCadサンプルデータのリポジトリです。

## KiCad_Project

KiCadプロジェクトです。回路図PDFを含みます。

## RP2040_breakout_KiCad_Symbol

[Picossci RP2040 ピッチ変換基板](https://ssci.to/8440)のKiCad用回路図シンボルとフットプリントデータです。この基板の販売ページで配布されている物と同じです。

## sample_software/rp2040_6key_pad_example

Raspberry Pi Pico C/C++ SDKを用いた簡単なサンプルソフトウェアです。USBシリアル変換アダプターとして機能し、押されたキーの番号をPCのシリアルポートへ送信します。
さらに押されたキーに対応するLEDが点灯します。簡単なREADME.mdを添付しています。

## qmk_firmware/qmk_configs_for_rp2040_6_keypad

QMK Firmwareをrp2040 6-key padに対応させるための設定ファイルとソースコードを書きました。ソースコード差分のみzipファイルにしています。
ビルド方法などの詳細は中のREADME.mdをご確認ください。
今回は6つのキーをBackspace、Enter、上下左右キーに割り振っています。LEDはCapsLockのLEDインジケーターとして動作します。

## prk_firmware/keymap.rb

PRK Firmware用のキーボード設定ファイルです。[PRK Firmware](https://github.com/picoruby/prk_firmware)のuf2ファイルを書き込み後、このファイルkeymap.rbをコピーしてください。キーマップや挙動を変更する時はこのkeymap.rbを書き換えるだけでいいのでQMK Firmwareに比べて試行が簡単です。
6つのキーには123456の数字を割り当ててあり、14、25、36のキーそれぞれを押すと対応したLEDが光ります。