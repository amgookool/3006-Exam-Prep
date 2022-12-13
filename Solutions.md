# Solutions to Problem Set Questions

## Question 1

**(i)** The SCP1000 barometric pressure sensor is the sensor being considered to interface through SPI communication protocol. The SPI interface is a full duplex 4-wire serial interface where the connection between the sensor the microcontroller (ESP8266 device) is done using the MOSI (Master Out Slave In), MISO (Master In Slave Out), SCLK (Serial Clock) and CS (Chip Select) I/O lines. The SCP1000 is configured to SPI slave mode.

The SPI communication frame contains two or three 8-bit words; the first word defines the register address (6-bits wide) followed by the bit to indicate the type of access (Read = 0 or Write = 1 ) and one zero-bit (LSB position). Lastly the third word is the data being read or written.

The MSB of the words are sent first where bits from the MOSI line are sampled in on the rising edge of the SCLK clock signal and bits to MISO line are latched out on the falling edge of SCLK.

The CS line stays low during the entire frame access process. If CS line changes to high, access is terminated.
The CS has to be pulled up after each communication frame.
The below C-routine indicates how the ESP8266-device will interface with the SCP1000 sensor.

```C
#define REVID_REG_ADDR 0x00
#define DATAWR_REG_ADDR 0x01
#define TEMPOUT_REG_ADDR 0x21

void write_data(uint8_t register_address, uint8_t data ){
    spi_master_transmit(register_address, 1, data);
}

void read_8bit_data(uint8_t register_address, uint8_t data){
    spi_master_read(register_address, 0, uint8_t data);
}

void read_16bit_data(uint8_t register_address, uint16_t data){
    spi_master_read(register_address, 0, data);
}

void app_main(void){
    uint8_t write_data = 0x55;
    uint8_t read8_data;
    uint16_t read16_data;
    init_esp_spi_protocol();
    write_data(DATA_WR_REG_ADDR, write_data);
    // Read from 8-bit data register 
    read_8bit_data(REVID_REG_ADDR, read8_data);
    // Read from 16-bit data register 
    read_8bit_data(TEMPOUT_REG_ADDR, read8_data);
}
```

**(i)** The Dallas 1-Wire Sensor is connected to one pin of the ESP8266 device. The transaction sequence for accessing the sensor is as follows:

1. Initialization

1. ROM command (followed by any required data exchange)

1. DS19B20 Function Command (followed by any required data exchange)

This wire sensor writes and reads data via a 64-bit lasered ROM code.
The below C-routine indicates how the ESP device interfaces with this sensor

```C
// ROM Command Set 
#define CMD_SEARCH_ROM 0xf0
#define CMD_READ_ROM 0x33
#define CMD_MATCH_ROM 0x55
#define CMD_SKIP_ROM 0xcc
#define CMD_ALARM_SEARCH 0xec
// Function Command Set
#define FUNC_CONVERT_T 0x44
#define FUNC_READ_SCRATCHPAD 0xbe
#define FUNC_WRITE_SCRATCHPAD 0x4e
#define FUNC_COPY_SCRATCHPAD 0x48
#define FUNC_RECALL_CONFIG 0xb8

void dallas_temp_init(void){
    esp_gpio_init();
    send_init_pulse();
}

void master_send_command(uint8_t cmd);
void master_send_function(uint8_t cmd);

void app_main(void){
    uint16_t data;
    dallas_temp_init(NULL);
    master_send_command(CMD_READ_ROM);
    master_send_function(FUNC_CONVERT);
    master_read_data(data);
}
```

## Question 2

### Case Study A : Leak Detection

### Case Study B : Driver Assistance

### Case Study C : Conveyor System
