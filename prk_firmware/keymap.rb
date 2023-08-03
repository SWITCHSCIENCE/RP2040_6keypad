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

gpio_init led_pin
gpio_init led_pin1
gpio_init led_pin2
gpio_init led_pin3
gpio_set_dir led_pin, Keyboard::GPIO_OUT
gpio_set_dir led_pin1, Keyboard::GPIO_OUT
gpio_set_dir led_pin2, Keyboard::GPIO_OUT
gpio_set_dir led_pin3, Keyboard::GPIO_OUT
gpio_put led_pin, 1
gpio_put led_pin1, 1
gpio_put led_pin2, 1
gpio_put led_pin3, 1

kbd.before_report do |keyboard|
  if kbd.key_pressed?
    gpio_put led_pin, 0
    gpio_put led_pin1, 0 if kbd.keys_include?(:KC_1)
    gpio_put led_pin2, 0 if kbd.keys_include?(:KC_2)
    gpio_put led_pin3, 0 if kbd.keys_include?(:KC_3)
    gpio_put led_pin1, 0 if kbd.keys_include?(:KC_4)
    gpio_put led_pin2, 0 if kbd.keys_include?(:KC_5)
    gpio_put led_pin3, 0 if kbd.keys_include?(:KC_6)
  else
    gpio_put led_pin, 1
    gpio_put led_pin1, 1
    gpio_put led_pin2, 1
    gpio_put led_pin3, 1
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
