
# qmk confings for RP2040 6-key pad

このソースコードはRP2040 6-Key Padをqmkに対応させるためのものです。

## 動作
### キーマッピング

デフォルトのキーマッピングは下記の通りです。`ssci/6_keypad/keymaps/default/keymap.c`を編集することで任意のキーマッピングを設定することができます。

左上のボタンがボタン1です。右下へ向けてボタン2,ボタン3と続きます。

- ボタン1 Backspaceキー
- ボタン2 上キー
- ボタン3 Enterキー
- ボタン4 左キー
- ボタン5 下キー
- ボタン6 右キー

### LED

LEDは左からNumLock, CapsLock, ScrollLockのインジケータLEDになっています。


## ビルド方法

下記URLのqmkのマニュアルに従ってqmkの開発環境をセットアップします。

https://docs.qmk.fm/#/newbs_getting_started

「3. Run QMK Setup」では`qmk setup -H <path>`コマンドを使ってqmkのディレクトリを指定すると今後の作業が楽になります。

「4. Test Your Build Environment」まで進めてビルドが成功することを確認します。

ssciディレクトリをqmkのソースコードのkeyboardsディレクトリ内にコピーします。

下記コマンドでコンパイルします。
```
qmk compile -kb ssci/6_keypad -km default
```
コンパイルが成功するとqmkソースコードのディレクトリに`ssci_6_keypad_default.uf2`が生成されます。

