#ifndef COMMON_CANID_H
#define COMMON_CANID_H

// CAN Nachrichten sind, wenn nicht anders angegeben MSB first

/***** Konstanten *****/
#define MAX_BOARD_ID 15
#define BL_MAX_BOARD_ID MAX_BOARD_ID
#define CAN_ECU_MSG_COUNT 4
#define CAN_DISPLAY_MSG_COUNT 4
#define TEXT_MAX_MSG_COUNT 20
#define TEXT_MAX_BOARD_COUNT 20
#define CAN_TIMESTAMP_INTERVAL 5
#define CAN_HVBMS_CELL_U_COUNT 48 // 96 cells / 3 Zellspannungen pro Nachricht
#define CAN_HVBMS_CELL_T_COUNT 12 // 40 cells / 5 Zelltemperaturen (1 stack) pro Nachricht
#define CAN_LVBMS_CELL_U_COUNT 3 // 14 cells? / 3 Zellspannungen pro Nachricht
#define CAN_LVBMS_CELL_T_COUNT 1 // Stub!

/***** CAN 1 IDs *****/
// ECU
 /*
  * Umgerechnete Gas-Werte
  * [0,1] Gas skaliert und gemittelt, Q0.16
  * [2,3] Gas L skaliert
  * [4,5] Gas R skaliert
  */
#define CAN_ID_ECU_TOR 0x072u // 0-1: Torque, 2-3: Torque L, 4-5: Torque R, 6: Break

/*
 * Umgerechnete Gas/Bremse-Werte
 * [0,1] Bremse, Q0.16
 * [2] Bremse gedrückt, bool
 */
#define CAN_ID_ECU_BRK 0x091u // 0-1: Torque, 2-3: Torque L, 4-5: Torque R, 6: Break

/*
 * Aktuell verwendete Raddrehzahlen in der ECU
 * [0,1] Vorne L
 * [2,3] Vorne R
 * [4,5] Hinten L
 * [6,7] Hinten R
 */
#define CAN_ID_ECU_SPEED 0x073u

/*
 * Umgerechneter Lenkwinkel
 * [0,1] Winkel / 0.001rad
 */
#define CAN_ID_ECU_STEERING 0x079u

/*
 * ECU Status
 * [0] Zustand, enum(Idle, NoBrake, Go, Locked)
 * [1] Sensorfehler, bitfield(
 *       Ungültiges Gas L, Ungültiges Gas R, Ungültige Gas Diff, Ungültige Gas Diff
 *       Ungültige Bremse, Gas/Bremse Timeout, Drehzahlen Vorne Timeout, Lenkwinkel Timeout)
 * [2,3] Sensorfehler-Zähler
 * [4,5] Auslastung, Q0.16
 * [6] RTDS-Timeout, ms
 */
#define CAN_ID_ECU_STATUS 0x074u

/*
 * FU Zustand der jeweiligen Seite
 * [0] Status, enum(Disconnected, Error, Connected, BTB, Go)
 * [1,2] FU Fehler, bitfield
 * [3,4] FU Warnungen, bitfield
 */
#define CAN_ID_ECU_STATUS_CTRL_L 0x070u
#define CAN_ID_ECU_STATUS_CTRL_R 0x071u

/*
 * FU Ströme
 * [0,1] Icmd, num
 * [2,3] Icmd, A / 10
 * [4,5] Iact, num
 */
#define CAN_ID_ECU_I_L 0x077u // ECU Stromwerte
#define CAN_ID_ECU_I_R 0x078u // ECU Stromwerte

/*
 * Raddrehzahlen für die jeweilige Seite
 * [0,1] Raddrehzahl vorne, num
 * [2,3] Raddrehzahl hinten, num
 * [4,5] Schlupf, num
 * [6,7] FU Drehzahlausgabe, num
 */
#define CAN_ID_ECU_N_L 0x075u // ECU Drehzahlen
#define CAN_ID_ECU_N_R 0x076u // ECU Drehzahlen

/*
 * Raddrehzahlen für die jeweilige Seite in RPM
 * [0,1] Raddrehzahl vorne, rpm
 * [2,3] Raddrehzahl hinten, rpm
 * [4,5] Motordrehzahl, rpm
 */
#define CAN_ID_ECU_N_RPM_L 0x094u // ECU Drehzahlen RPM
#define CAN_ID_ECU_N_RPM_R 0x095u // ECU Drehzahlen RPM

/*
 * Temperaturen von Motor und FU-Endstufe (°C bzw num)
 * [0,1] Temperatur Motor
 * [2,3] Temperatur IGBT
 * [4,5] Temperatur Luft
 */
#define CAN_ID_ECU_T_L 0x096u
#define CAN_ID_ECU_T_R 0x097u
#define CAN_ID_ECU_T_RAW_L 0x098u
#define CAN_ID_ECU_T_RAW_R 0x099u

/*
 * Zwischenkreisspannung (für BMS)
 * [0,1] Vdc (LSB first), num
 */
#define CAN_ID_ECU_VDC_L 0x520u
#define CAN_ID_ECU_VDC_R 0x521u

/*
 * Request zum Auslesen und übertragen eines FU-Registers
 *  auslesen
 * [0] Bitfeld: 0x01: FU-Index, L=0, R=1, 0x80: Lesen=0, Schreiben=1
 * [1] Reg ID
 */
#define CAN_ID_ECU_DRIVE_REQ 0x080u

/*
 * Antwort auf einen Request mit dem Inhalt des Registers
 * [0] FU-Index
 * [1] Reg ID
 * [2,3] | [2,3,4,5] Data
 */
#define CAN_ID_ECU_DRIVE_RES 0x081u

/*
 * Fahrzeuggeschwindigkeit
 * [0,1] V vorne, i16, km/h
 * [2,3] V hinten, i16, km/h
 * [4,5] Zurückgelegte Strecke s, i16, m
 */
#define CAN_ID_ECU_V 0x090u

/*
 * Regler-Strom-Limits
 * [0,1] I LimitP L
 * [2,3] I LimitP R
 * [4,5] I LimitN
 */
#define CAN_ID_ECU_CTRL_ILIMITS 0x092u

/*
 * Regler-Drehzahl-Limits
 * [0,1] N Limit L
 * [2,3] N Limit R
 */
#define CAN_ID_ECU_CTRL_NLIMITS 0x096u

/*
 * ECU-geschätzte Leistung und Messwerte
 * [0,1] P L
 * [2,3] P R
 * [4,5] P FU L, i16, num
 * [6,7] P FU R, i16, num
 */
#define CAN_ID_ECU_P 0x093u

/*
 * ECU Leistungslimit
 * [0,1] P limit, kW
 */
#define CAN_ID_ECU_P_LIMIT 0x524u

/*
 * Textausgaben der ECU
 * [0-8] Text, nicht '\0'-terminiert, die Länge der Nachrichten
 *        ist auf die Länge des Texts angepasst, es werden immer
 *        alle Nachrichten gesendet, gegebenenfalls leer
 */
#define CAN_ID_ECU_MSG_START 0x610u
#define CAN_ID_ECU_MSG_END (CAN_ID_ECU_MSG_START + CAN_ECU_MSG_COUNT - 1)

// Sensoren
/*
 * ADC-Werte für Gas und Bremse (LSB first)
 * [0,1]: Gas L
 * [2,3]: Gas R
 * [4,5]: Bremse
 */
#define CAN_ID_SENSOR_ACC_BRK 0x082u

/*
 * ADC-Werte für die Bremsdrücke (LSB first)
 * [0,1]: Bremsdruck V
 * [2,3]: Bremsdruck H
 */
#define CAN_ID_SENSOR_BRKPRE 0x083

/*
 * Drehzahlen der Vorderräder (LSB first)
 * [0,1]: L; RPM
 * [2,3]: R; RPM
 */
#define CAN_ID_SENSOR_N_FRONT 0x085u

/*
 * ADC-Wert des Lenkwinkelsensors
 * [0,1]: ???
 * [2,3]: Lenkwinkel
 */
#define CAN_ID_SENSOR_STEERING 0x601u

/*
 * Bremsdruck in Bar (0-250)
 * [0]: V; Bar
 * [1]: H; Bar
 * [2,3]: V raw; num
 * [4,5]: H raw; num
 */
#define CAN_ID_SENSOR_BRK_BAR 0x602u

/*
 * Federweg in mm (25-200)
 * [0]: VR; mm
 * [1]: VL; mm
 * [2]: HR; mm
 * [3]: HL; mm
 */
#define CAN_ID_SENSOR_SUS_MM 0x603u

// IVT Messages
/*
 * Konfigurationsnachricht für das IVT-Messgerät
 */
#define CAN_ID_IVT_CONFIG 0x411u

/*
 * Strommesswert in des IVT Moduls
 * [0]: Messwert ID
 * [1]: Message counter
 * [2,3,4,5]: Messwert (LSB first)
 */
#define CAN_ID_IVT_CURRENT 0x519u
#define CAN_ID_IVT_POWER 0x526u


// HV BMS
#define CAN_ID_HVBMS_BASE 0x620u
#define CAN_ID_HVBMS_REV (CAN_ID_HVBMS_BASE + 1)
#define CAN_ID_HVBMS_STATE (CAN_ID_HVBMS_BASE + 2)

/*
 * avg, min, max Spannung (0.1mV, MSB first)
 * [0,1] Uavg
 * [2,3] Umin
 * [4] Zellnummer
 * [5,6] Umax
 * [7] Zellnummer
 */
#define CAN_ID_HVBMS_U_AVG (CAN_ID_HVBMS_BASE + 3)
#define CAN_ID_HVBMS_I_AVG (CAN_ID_HVBMS_BASE + 4) // Current
#define CAN_ID_HVBMS_W (CAN_ID_HVBMS_BASE + 5) // Energy
#define CAN_ID_HVBMS_SOC_C (CAN_ID_HVBMS_BASE + 6) // SOC Capacity

 /*
 * min, max Temps (1/3°C)
 * [0] Tmin
 * [1] Tmax
 * [2] Tmin (kein Typo ;))
 * [3] dcc_number (?)
 * [4] Tmax
 * [5] 0 (wtf?, wahrscheinlich wg Kompatibilität)
 */
#define CAN_ID_HVBMS_T_AVG (CAN_ID_HVBMS_BASE + 7)
#define CAN_ID_HVBMS_R (CAN_ID_HVBMS_BASE + 8) // Resistance
#define CAN_ID_HVBMS_CONTACTOR 0x632u
#define CAN_ID_HVBMS_PID_REQ 0x745u // PID request
#define CAN_ID_HVBMS_PID_RES (CAN_ID_HVBMS_PID_REQ + 8) // PID response
#define CAN_ID_HVBMS_DATA_DUMP 0x640u
#define CAN_ID_HVBMS_CELL_U_START 0x380u
#define CAN_ID_HVBMS_CELL_U_END (CAN_ID_HVBMS_CELL_U_START + CAN_HVBMS_CELL_U_COUNT - 1)
#define CAN_ID_HVBMS_CELL_T_START 0x480u
#define CAN_ID_HVBMS_CELL_T_END (CAN_ID_HVBMS_CELL_T_START + CAN_HVBMS_CELL_T_COUNT - 1)
#define CAN_ID_HVBMS_STATUS 0x700u
// LV BMS (stubs!)
#define CAN_ID_LVBMS_BASE 0x520u
#define CAN_ID_LVBMS_U_AVG (CAN_ID_LVBMS_BASE + 3)
#define CAN_ID_LVBMS_T_AVG (CAN_ID_LVBMS_BASE + 7)
#define CAN_ID_LVBMS_CELL_U_START 0x280u
#define CAN_ID_LVBMS_CELL_U_END (CAN_ID_LVBMS_CELL_U_START + CAN_LVBMS_CELL_U_COUNT - 1)
#define CAN_ID_LVBMS_CELL_T_START 0x580u
#define CAN_ID_LVBMS_CELL_T_END (CAN_ID_LVBMS_CELL_T_START + CAN_LVBMS_CELL_T_COUNT - 1)
// Text interface
#define CAN_ID_TEXT_START 0x7a0u // Board -> PC
#define CAN_ID_TEXT_CMD_START 0x770u // PC -> Board
#define CAN_ID_TEXT_CMD_END (CAN_ID_TEXT_CMD_START + TEXT_MAX_BOARD_COUNT)
// STM32 Bootloader
#define CAN_ID_BL_CTRL 0x020u // Nachrichten von ryctl
#define CAN_ID_BL_START 0x020u // Boardnachrichten. ID == 0x00 ist reserviert
#define CAN_ID_BL_END (CAN_ID_BL_START + BL_MAX_BOARD_ID)
// At90can Bootloader
#define CAN_ID_BL_RES 0x7feu
#define CAN_ID_BL_CMD 0x7ffu

// Display
/*
 * Anzeigen von Text auf dem Display. Zwei Nachrichten pro Zeile
 * [0-8] Zeichen zum Anzeigen, leere Zeichen sind Spaces (' ')
 */
#define CAN_ID_DISPLAY_MSG_START 0x7d0u
#define CAN_ID_DISPLAY_MSG_END (CAN_ID_DISPLAY_MSG_START + CAN_DISPLAY_MSG_COUNT - 1)

// Utils
/*
 * Board reset (zB für das Nutzen des Bootloaders)
 * [0] Board ID oder 0x00 für Broadcast
 */
#define CAN_ID_BOARD_RESET 0x100u
/*
 * Not-Aus
 * [0] 0xba
 * [1] 0xdd
 * [2] 0x00
 * [3] 0xdd
 * [4] 0x0f
 * [5] 0xa5
 * [6] 0x70
 * [7] 0xff
 * Wiedereinschalten
 * [0] 0xde
 * [1] 0xad
 * [2] 0xbe
 * [3] 0xef
 * [4] 0xde
 * [5] 0xad
 * [6] 0xc0
 * [7] 0xde
 */
#define CAN_ID_SHUTDOWN 0x017

// Logs
/*
 * Timestamp, werden alle 5ms in Log-Dateien eingebaut (LSB first)
 * [0,1,2,3] ms seit Start des Logs
 */
#define CAN_ID_TIMESTAMP 0x069u // Log timestamps (alle 5ms)

/*
 * RTC-Zeit
 * [0] Sekunden
 * [1] Minuten
 * [2] Stunden
 * [3] Tag
 * [4] Monat
 * [5] Jahr
 * [6,7] ???
 */
#define CAN_ID_TIME 0x6f0u

/*
 * Setzen der RTC-Zeit, aktuell ungenutzt, kann durch Text Interface ersetzt werden
 */
#define CAN_ID_TIME_SET 0x6f1u

/***** CAN 2 IDs (ECU <-> FU) *****/

/*
 * FU -> ECU Nachrichten (LSB first)
 * [0] Register ID
 * [1,2] | [1,2,3,4] Data
 */
#define CAN_ID_CTRL_L_RX 0x181u
#define CAN_ID_CTRL_R_RX 0x182u

/*
 * FU -> ECU Nachrichten (LSB first)
 * [0] Register ID
 * [1,2] | [1,2,3,4] Data
 * [3] | [5] Update-Frequenz in ms
 */
#define CAN_ID_CTRL_L_TX 0x201u
#define CAN_ID_CTRL_R_TX 0x202u

#endif
