# Visible Light Communication-(LIFI)
codes for transmitter and receiver for LDR based Data transmission and reception
# 💡 Visible Light Communication (VLC) using LDR and LED

A **Li-Fi (Light Fidelity)** system implemented using an **Arduino-based transmitter and receiver** that communicates data over visible light. The transmitter encodes characters into binary using an LED, and the receiver decodes the light pulses using an LDR (Light Dependent Resistor).

---

## 📁 Project Structure

- `fTransmitter` – File containing transmittter code
- `newreciver` – File containing receiver code
- `README.md` – Project documentation

---

## 🎯 Objective

To demonstrate **wireless data transmission using visible light** by modulating the LED to represent binary data and capturing it via an LDR.

---

## 🧠 How It Works

### 📤 Transmitter (`transmitter.ino`)
- Accepts text via Serial Monitor.
- Converts each character into an 8-bit binary format.
- Sends bits using an LED: `HIGH = 1`, `LOW = 0`, with timed delays.

### 📥 Receiver (`receiver.ino`)
- Continuously reads analog values from the LDR.
- Decodes the incoming light pulses into binary.
- Reconstructs each byte into a character.
- Prints the received message to the Serial Monitor.

---

## 🔌 Circuit Diagram & Connections

### 🟡 Transmitter (LED)
| Component         | Pin  |
|------------------|------|
| LED              | D11  |
| Button (Optional)| D3   |

### 🔵 Receiver (LDR)
| Component         | Pin  |
|------------------|------|
| LDR (via voltage divider) | A6 |
| Indicator LED     | A4   |

💡 **Note:** Place the LDR directly facing the transmitting LED for better reception.

---

## 🛠️ Hardware Required

- 2 × Arduino Uno/Nano
- 1 × LED (for transmitting data)
- 1 × LDR sensor (with 10kΩ resistor)
- 1 × Breadboard and jumper wires
- USB cables for programming and power

---

## 🕹️ How to Use

### 🚀 Upload & Run

1. Connect the transmitter and receiver circuits as described above.
2. Open **Arduino IDE** or **VS Code with PlatformIO**.
3. Upload `transmitter.ino` to the Transmitter Arduino.
4. Upload `receiver.ino` to the Receiver Arduino.
5. Open **Serial Monitor** for both boards at `9600 baud`.

### 📝 Transmit Data

1. In the transmitter’s Serial Monitor, type any message (e.g., `Hello`).
2. Press **Enter** to send the message using visible light.
3. The receiver will reconstruct and display the message in its Serial Monitor.

---

## ⚙️ Configuration

- **Sampling Time:** `20 ms` per bit
- **Protocol:** Start → 8-bit character → Stop (idle)
- **LDR Threshold:** `analogRead(A6) > 90` = HIGH, else LOW

---

---

## 📦 Enhancements (Optional Ideas)

- ✅ Add checksum or parity bits for error detection
- ✅ Use Manchester encoding for synchronization
- ✅ Integrate OLED/Display to show received text
- ✅ Use laser or IR LED for long-distance VLC

---

## 👤 Author

**Parth Manekar**  
📧 parthmanekar25@gmail.com  
🔗 [GitHub Profile](https://github.com/parthmanekar25)

---

## 🙌 Acknowledgements

- Concept inspired by real-world **Li-Fi systems**
- Ideal for demonstrations in **IoT**, **Wireless Communication**, and **Embedded Systems** projects


