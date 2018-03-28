/* 
 * File:   artnet.h
 * Author: upboard01
 *
 * Created on 19 marca 2018, 18:08
 */

#ifndef ARTNET_H
#define	ARTNET_H

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* ARTNET_H */

#define ART_NET_PORT 6454
// Opcodes
#define ART_POLL 0x2000
#define ART_POLL_REPLY 0x2100
#define ART_DMX 0x5000
// Buffers
#define MAX_BUFFER_ARTNET 530
// Packet
#define ART_NET_ID "Art-Net"
#define ART_DMX_START 18
#define MAX_DMX_SLOTS 512
extern uint16_t inUniverse; 




typedef struct _ArtPollPack_t
{
    uint8_t ID[8];
    uint16_t OpCode;      // The OpCode defines the class of data following ArtPoll within this UDP packet. Transmitted low byte first.
    uint8_t ProtVerHi;    // High byte of the Art-Net protocol revision number.
    uint8_t ProtVerLo;    // Low byte of the Art-Net protocol revision number. Current value 14.
                            // Controllers should ignore communication with nodes using a protocol version lower than 14.
    uint8_t TalkToMe;     // Set behavichar* Art_net_ID="Art-net";our of Node
    uint8_t Priority;     // The lowest priority of diagnostics message that should be sent.
    
} ArtPollPack_t;


typedef struct _ArtPollReplyPack_t
{
    uint8_t ID[8];
    uint16_t OpCode;          // OpPollReply. Transmitted low byte first.
    uint8_t IpAddress[4];     // Array containing the Node?s IP address. First array entry is most significant byte of address.
    uint16_t Port;            // The Port is always 0x1936. Transmitted low byte first.
    uint8_t VersInfoH;        // High byte of Node?s firmware revision number. The Controller should only use this field to decide
                                // if a firmware update should proceed. The convention is that a higher number is a more recent release of firmware.
    uint8_t VersInfoL;        // Low byte of Node?s firmware revision number.
    uint8_t NetSwitch;        // Bits 14-8 of the 15 bit Port-Address are encoded into the bottom 7 bits of this field.
                                // This is used in combination with SubSwitch and SwIn[] or SwOut[] to produce the full universe address.
    uint8_t SubSwitch;        // Bits 7-4 of the 15 bit Port-Address are encoded into the bottom 4 bits of this field.
                                // This is used in combination with NetSwitch and SwIn[] or SwOut[] to produce the full universe address.
    uint8_t OemHi;            // The high byte of the Oem value.
    uint8_t OemL;             // The low byte of the Oem value. The Oem word describes the equipment vendor and
                                // the feature set available. Bit 15 high indicates extended features available.
    uint8_t UbeaVersion;      // This field contains the firmware version of the User Bios Extension Area (UBEA).
                                // If the UBEA is not programmed, this field contains zero.
    uint8_t Status1;          // General Status register
                                // Bit:
                                // 7-6 Indicator state.
                                //      00 Indicator state unknown.
                                //      01 Indicators in Locate Mode.
                                //      10 Indicators in Mute Mode.
                                //      11 Indicators in Normal Mode.
                                // 5-4 Port Address Programming Authority
                                //      00 Port Address Programming Authority unknown.
                                //      01 All Port Address set by front panel controls.
                                //      10 All or part of Port Address programmed by network.
                                //      11 Not used.
                                // 3 Not implemented, transmit as zero, receivers do not test.
                                // 2 0 = Normal firmware boot (from flash). Nodes that do not support dual boot, clear this field to zero.
                                //   1 = Booted from ROM.
                                // 1 0 = Not capable of Remote Device Management (RDM).
                                //   1 = Capable of Remote Device Management (RDM).
                                // 0 0 = UBEA not present or corrupt
                                //   1 = UBEA present
    uint8_t EstaManLo;        // The ESTA manufacturer code. These codes are used to represent equipment manufacturer. They are assigned by ESTA.
                                // This field can be interpreted as two ASCII bytes representing the manufacturer initials.
    uint8_t EstaManHi;        // Hi byte of above
    uint8_t ShortName [18];   // The array represents a null terminated short name for the Node. The Controller uses the ArtAddress packet
                                // to program this string. Max length is 17 characters plus the null. This is a fixed length field,
                                // although the string it contains can be shorter than the field.
    uint8_t LongName [64];    // The array represents a null terminated long name for the Node. The Controller uses the ArtAddress packet
                                // to program this string. Max length is 63 characters plus the null. This is a fixed length field,
                                // although the string it contains can be shorter than the field.
    uint8_t NodeReport[64];   // The array is a textual report of the Node?s operating status or operational errors. It is primarily intended
                                // for ?engineering? data rather than ?end user? data. The field is formatted as: ?#xxxx [yyyy..] zzzzz??
                                // xxxx is a hex status code as defined in Table 3. yyyy is a decimal counter
                                // that increments every time the Node sends an ArtPollResponse. This allows the controller to monitor event changes in the Node.
                                // zzzz is an English text string defining the status.
                                // This is a fixed length field, although the string it contains can be shorter than the field.
    uint8_t NumPortsHi;       // The high byte of the word describing the number of input or output ports.
                                // The high byte is for future expansion and is currently zero.
    uint8_t NumPortsLo;       // The low byte of the word describing the number of input or output ports. If number of inputs is not equal to number of outputs,
                                // the largest value is taken. Zero is a legal value if no input or output ports are implemented. The maximum value is 4.
    uint8_t PortTypes[4];     // This array defines the operation and protocol of each channel. (Ether-Lynx example = 0xc0, 0xc0, 0xc0, 0xc0).
                                // The array length is fixed, independent of the number of inputs or outputs physically available on the Node.
                                // Bit:
                                // 7 Set is this channel can output data from the Art-Net Network.
                                // 6 Set if this channel can input onto the Art-NetNetwork.
                                // 5-0 00000 = DMX512
                                //     00001 = MIDI
                                //     00010 = Avab
                                //     00011 = Colortran CMX
                                //     00100 = ADB 62.5
                                //     00101 = Art-Net
    uint8_t GoodInput[4];     // This array defines input status of the node.
                                // Bit:
                                // 7 Set ? Data received.
                                // 6 Set ? Channel includes DMX512 test packets.
                                // 5 Set ? Channel includes DMX512 SIP?s.
                                // 4 Set ? Channel includes DMX512 text packets.
                                // 3 Set ? Input is disabled.
                                // 2 Set ? Receive errors detected.
                                // 1-0 Unused and transmitted as zero.
    uint8_t GoodOutput[4];    // This array defines output status of the node.
                                // Bit:
                                // 7 Set ? Data is being transmitted.
                                // 6 Set ? Channel includes DMX512 test packets.
                                // 5 Set ? Channel includes DMX512 SIP?s.
                                // 4 Set ? Channel includes DMX512 text packets.
                                // 3 Set ? Output is merging ArtNet data.
                                // 2 Set ? DMX output short detected on power up
                                // 1 Set ? Merge Mode is LTP.
                                // 0 Unused and transmitted as zero.
    uint8_t SwIn[4];          // Bits 3-0 of the 15 bit Port-Address for each of the 4 possible input ports are encoded into the low nibble.
    uint8_t SwOut[4];         // Bits 3-0 of the 15 bit Port-Address for each of the 4 possible output ports are encoded into the low nibble.
    uint8_t SwVideo;          // Set to 00 when video display is showing local data. Set to 01 when video is showing ethernet data.
    uint8_t SwMacro;          // If the Node supports macro key inputs, this byte represents the trigger values.
                                // The Node is responsible for ?debouncing? inputs. When the ArtPollReply is set to transmit automatically,
                                // (TalkToMe Bit 1), the ArtPollReply will be sent on both key down and key up events.
                                // However, the Controller should not assume that only one bit position has changed.
                                // The Macro inputs are used for remote event triggering or cueing. Bit fields are active high.
                                // Bit:
                                // 7 Set ? Macro 8 active.
                                // 6 Set ? Macro 7 active.
                                // 5 Set ? Macro 6 active.
                                // 4 Set ? Macro 5 active.
                                // 3 Set ? Macro 4 active.
                                // 2 Set ? Macro 3 active.
                                // 1 Set ? Macro 2 active.
                                // 0 Set ? Macro 1 active.
    uint8_t SwRemote;         // If the Node supports remote trigger inputs, this byte represents the trigger values.
                                // The Node is responsible for ?debouncing? inputs. When the ArtPollReply is set to transmit automatically,
                                // (TalkToMe Bit 1), the ArtPollReply will be sent on both key down and key up events.
                                // However, the Controller should not assume that only one bit position has changed.
                                // The Remote inputs are used for remote event triggering or cueing. Bit fields are active high.
                                // Bit:
                                // 7 Set ? Remote 8 active.
                                // 6 Set ? Remote 7 active.
                                // 5 Set ? Remote 6 active.
                                // 4 Set ? Remote 5 active.
                                // 3 Set ? Remote 4 active.
                                // 2 Set ? Remote 3 active.
                                // 1 Set ? Remote 2 active.
                                // 0 Set ? Remote 1 active.
    uint8_t Spare1[3];        // Not used, set to zero
    uint8_t Style;            // The Style code defines the equipment style of the device.
    uint8_t MAC[6];           // MAC Address.  Hi Byte is sent first. Set to zero if node cannot supply this information.
    uint8_t BindIp[4];        // If this unit is part of a larger or modular product, this is the IP of the root device.
    uint8_t BindIndex;        // Set to zero if no binding, otherwise this number represents the order of bound devices.
                                // A lower number means closer to root device. A value of 1 means root device.
    uint8_t Status2;          // Bit:
                                // 0 Set = Product supports web browser configuration.
                                // 1 Clr = Node?s IP is manually configured.
                                //   Set = Node?s IP is DHCP configured.
                                // 2 Clr = Node is not DHCP capable.
                                //   Set = Node is DHCP capable.
                                // 3 Clr = Node supports 8 bit Port-Address (Art-Net II).
                                //   Set = Node supports 15 bit Port-Address (Art-Net 3).
    uint8_t Filler[26];       // Transmit as zero. For future expansion.

} ArtPollReplyPack_t;

typedef struct _ArtDmxPack_t
{
    uint8_t ID[8];        // Array of 8 characters, the final character is a null termination. Value = ?A? ?r? ?t? ?-? ?N? ?e? ?t? 0x00
    uint16_t OpCode;      // OpOutput Transmitted low byte first.
    uint8_t ProtVerHi;    // High byte of the Art-Net protocol revision number.
    uint8_t ProtVerLo;    // Low byte of the Art-Net protocol revision number. Current value 14
    uint8_t Sequence;     // The sequence number is used to ensure that ArtDmx packets are used in the correct order.
                            // When Art-Net is carried over a medium such as the Internet,
                            // it is possible that ArtDmx packets will reach the receiver out of order.
                            // This field is incremented in the range 0x01 to 0xff to allow the receiving node to resequence packets.
                            // The Sequence field is set to 0x00 to disable this feature.
    uint8_t Physical;     // The physical input port from which DMX512 data was input. This field is for information only.
                            // Use Universe for data routing.
    uint8_t SubUni;       // The low byte of the 15 bit Port-Address to which this packet is destined.
    uint8_t Net;          // The top 7 bits of the 15 bit Port-Address to which this packet is destined.
    uint8_t LengthHi;     // The length of the DMX512 data array. This value should be an even number in the range 2 ? 512.
                            // It represents the number of DMX512 channels encoded in packet.
                            // NB: Products which convert Art-Net to DMX512 may opt to always send 512 channels. High Byte.
    uint8_t Length;       // Low Byte of above.

    uint8_t Data[MAX_DMX_SLOTS];    // An variable length array of DMX512 lighting data.

} ArtDmxPack_t;

typedef union 
{
  uint8_t answer[240];
  ArtPollReplyPack_t poll_reply;
}Paczka_t;

uint16_t checkArtnet(uint8_t *packet); 
void ArtPollReplyPack(uint8_t *packet,uint8_t *dest_IP, uint16_t port);

/* typedef struct _ArtIpProgPack_t
{
    uint8_t ID[8];        // Array of 8 characters, the final character is a null termination. Value = ?A? ?r? ?t? ?-? ?N? ?e? ?t? 0x00
    uint16_t OpCode;      // OpIpProg Transmitted low byte first.
    uint8_t ProtVerHi;    // High byte of the Art-Net protocol revision number.
    uint8_t ProtVerLo;    // Low byte of the Art-Net protocol revision number. Current value 14
    uint8_t Filler1;      // Pad length to match ArtPoll.
    uint8_t Filler2;      // Pad length to match ArtPoll.
    uint8_t Command;      // Action this packet as follows:
                            // Defines the how this packet is processed. If all bits are clear, this is an enquiry only.
                            // 7 Set to enable any programming.
                            // 6 Set to enable DHCP (if set ignore lower bits).
                            // 5-4 Not used, transmit as zero
                            // 3 Set to return all three parameters to default
                            // 2 Program IP Address
                            // 1 Program Subnet Mask
                            // 0 Program Port
    uint8_t Filler4;  // Set to zero. Pads data structure for word alignment.
    uint8_t ProgIpHi; // IP Address to be programmed into Node if enabled by Command Field
    uint8_t ProgIp2;
    uint8_t ProgIp1;
    uint8_t ProgIpLo;
    uint8_t ProgSmHi; // Subnet mask to be programmed into Node if enabled by Command Field
    uint8_t ProgSm2;
    uint8_t ProgSm1;
    uint8_t ProgSmLo;
    uint8_t ProgPortHi;   // PortAddress to be programmed into Node if enabled by Command Field
    uint8_t ProgPortLo;
    uint8_t Spare[8];     // Transmit as zero, receivers don?t test.
    
} ArtIpProgPack_t; */

