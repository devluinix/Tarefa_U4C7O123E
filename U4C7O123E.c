#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

#define SERVO_PIN 22
#define LED_PIN 12

int main(void)
{
    stdio_init_all();

    // Configuração do servo (GPIO 22)
    gpio_set_function(SERVO_PIN, GPIO_FUNC_PWM);
    uint slice_servo = pwm_gpio_to_slice_num(SERVO_PIN);
    uint channel_servo = pwm_gpio_to_channel(SERVO_PIN);
    pwm_set_clkdiv(slice_servo, 125.f); // 125MHz/125 = 1MHz (1 µs por contagem)
    pwm_set_wrap(slice_servo, 19999);   // Período de 20ms (20000 µs)
    pwm_set_enabled(slice_servo, true);

    // Configuração do LED (GPIO 12)
    gpio_set_function(LED_PIN, GPIO_FUNC_PWM);
    uint slice_led = pwm_gpio_to_slice_num(LED_PIN);
    uint channel_led = pwm_gpio_to_channel(LED_PIN);
    pwm_set_clkdiv(slice_led, 125.f); // 1 µs por contagem
    pwm_set_wrap(slice_led, 999);     // Período de 1ms (1 kHz)
    pwm_set_enabled(slice_led, true);

    // Variáveis para controle do servo
    uint servo_value = 500;      // Inicia em 0° (~500 µs)
    int servo_step = 5;          // Incremento de 5 µs
    const uint servo_min = 500;  // 0° ~500 µs
    const uint servo_max = 2400; // 180° ~2400 µs

    // Variáveis para controle do LED
    uint led_value = 0; // Inicia apagado
    int led_step = 5;   // Passo de 5 (de 0 a 999)
    const uint led_min = 0;
    const uint led_max = 999;

    // Intervalos de atualização (em microsegundos)
    uint32_t last_servo_update = time_us_32();
    uint32_t last_led_update = time_us_32();
    const uint32_t update_interval = 10000; // 10 ms para ambos

    pwm_set_chan_level(slice_servo, channel_servo, 2400);
    sleep_ms(5000);

    // 90°: ciclo ativo de 1470µs
    pwm_set_chan_level(slice_servo, channel_servo, 1470);
    sleep_ms(5000);

    // 0°: ciclo ativo de 500µs
    pwm_set_chan_level(slice_servo, channel_servo, 500);
    sleep_ms(5000);

    while (true)
    {
        uint32_t now = time_us_32();

        // Atualização assíncrona do servo
        if (now - last_servo_update >= update_interval)
        {
            last_servo_update = now;
            servo_value += servo_step;
            if (servo_value >= servo_max || servo_value <= servo_min)
            {
                servo_step = -servo_step; // Inverte a direção
            }
            pwm_set_chan_level(slice_servo, channel_servo, servo_value);
        }

        // Atualização assíncrona do LED (efeito fade)
        if (now - last_led_update >= update_interval)
        {
            last_led_update = now;
            led_value += led_step;
            if (led_value >= led_max || led_value <= led_min)
            {
                led_step = -led_step; // Inverte o sentido do fade
            }
            pwm_set_chan_level(slice_led, channel_led, led_value);
        }
        sleep_ms(10);
    }

    return 0;
}
