kbd = Keyboard.new
kbd.init_direct_pins(
  [ 0,1,2,3,4,5 ]
)
kbd.add_layer :default, %i(
  KC_1    KC_2    KC_3    KC_4    KC_5    KC_6
)

led_pin = 25 # It's the on-board LED of Raspi Pico
led_pin1 = 28
led_pin2 = 27
led_pin3 = 26

# GPIOクラスを使用してLEDピンを初期化
GPIO.new(led_pin, GPIO::OUT)
GPIO.new(led_pin1, GPIO::OUT)
GPIO.new(led_pin2, GPIO::OUT)
GPIO.new(led_pin3, GPIO::OUT)

# 初期状態でLEDをON（1）
GPIO.write_at(led_pin, 1)
GPIO.write_at(led_pin1, 1)
GPIO.write_at(led_pin2, 1)
GPIO.write_at(led_pin3, 1)

kbd.before_report do |keyboard|
  if kbd.key_pressed?
    # キーが押されたらメインLEDをOFF
    GPIO.write_at(led_pin, 0)
    
    # 各キーに対応するLEDをOFF
    GPIO.write_at(led_pin1, 0) if kbd.keys_include?(:KC_1)
    GPIO.write_at(led_pin2, 0) if kbd.keys_include?(:KC_2)
    GPIO.write_at(led_pin3, 0) if kbd.keys_include?(:KC_3)
    GPIO.write_at(led_pin1, 0) if kbd.keys_include?(:KC_4)
    GPIO.write_at(led_pin2, 0) if kbd.keys_include?(:KC_5)
    GPIO.write_at(led_pin3, 0) if kbd.keys_include?(:KC_6)
  else
    # キーが押されていない時はすべてのLEDをON
    GPIO.write_at(led_pin, 1)
    GPIO.write_at(led_pin1, 1)
    GPIO.write_at(led_pin2, 1)
    GPIO.write_at(led_pin3, 1)
  end
end

kbd.start!

# GP0 SW1
# GP1 SW2
# GP2 SW3
# GP3 SW4
# GP4 SW5
# GP5 SW6
# GP26 LED3
# GP27 LED2
# GP28 LED1
# GP16-22 pinheader
