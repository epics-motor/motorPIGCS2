///////////////////////////////////////////////////////////////////////////
//                                                                       //
//     _                     _              _ _ _     _   _     _        //
//    | |                   | |            | (_) |   | | | |   (_)       //
//  __| | ___    _ __   ___ | |_    ___  __| |_| |_  | |_| |__  _ ___    //
// / _` |/ _ \  | |_ \ / _ \| __|  / _ \/ _| | | __| | __| |_ \| / __|   //
//| (_| | (_) | | | | | (_) | |_  |  __/ (_| | | |_  | |_| | | | \__ \   //
// \__,_|\___/  |_| |_|\___/ \__|  \___|\__,_|_|\__|  \__|_| |_|_|___/   //
//                                                                       //
//                                                                       //
//  __ _ _      _ _ _                                                    //
// / _(_) |    | | | |                                                   //
//| |_ _| | ___| | | |                                                   //
//|  _| | |/ _ \ | | |                                                   //
//| | | | |  __/_|_|_|                                                   //
//|_| |_|_|\___(_|_|_)                                                   //
//                                                                       //
///////////////////////////////////////////////////////////////////////////
//
// If you want to add/update/delete an error code, please follow the
// instructions in the README.md of this project
//

#include "picontrollererrors.h"
#include <string>
#include <cstring>
#include <sstream>
#include <epicsTypes.h>

std::string TranslatePIError(epicsInt32 error)
{
    switch(error)
    {

///////////////////////////////////////////////////////////////////////////////
//
// Interface Errors - Interface errors occuring while communicating with the controller
//
///////////////////////////////////////////////////////////////////////////////

        case(COM_ERROR):
        {
            return "Error during com operation (could not be specified)";
        }
        case(SEND_ERROR):
        {
            return "Error while sending data";
        }
        case(REC_ERROR):
        {
            return "Error while receiving data";
        }
        case(NOT_CONNECTED_ERROR):
        {
            return "Not connected (no port with given ID open)";
        }
        case(COM_BUFFER_OVERFLOW):
        {
            return "Buffer overflow";
        }
        case(CONNECTION_FAILED):
        {
            return "Error while opening port";
        }
        case(COM_TIMEOUT):
        {
            return "Timeout error";
        }
        case(COM_MULTILINE_RESPONSE):
        {
            return "There are more lines waiting in buffer";
        }
        case(COM_INVALID_ID):
        {
            return "There is no interface or DLL handle with the given ID";
        }
        case(COM_NOTIFY_EVENT_ERROR):
        {
            return "Event/message for notification could not be opened";
        }
        case(COM_NOT_IMPLEMENTED):
        {
            return "Function not supported by this interface type";
        }
        case(COM_ECHO_ERROR):
        {
            return "Error while sending \"echoed\" data";
        }
        case(COM_GPIB_EDVR):
        {
            return "IEEE488: System error";
        }
        case(COM_GPIB_ECIC):
        {
            return "IEEE488: Function requires GPIB board to be CIC";
        }
        case(COM_GPIB_ENOL):
        {
            return "IEEE488: Write function detected no listeners";
        }
        case(COM_GPIB_EADR):
        {
            return "IEEE488: Interface board not addressed correctly";
        }
        case(COM_GPIB_EARG):
        {
            return "IEEE488: Invalid argument to function call";
        }
        case(COM_GPIB_ESAC):
        {
            return "IEEE488: Function requires GPIB board to be SAC";
        }
        case(COM_GPIB_EABO):
        {
            return "IEEE488: I/O operation aborted";
        }
        case(COM_GPIB_ENEB):
        {
            return "IEEE488: Interface board not found";
        }
        case(COM_GPIB_EDMA):
        {
            return "IEEE488: Error performing DMA";
        }
        case(COM_GPIB_EOIP):
        {
            return "IEEE488: I/O operation started before previous operation completed";
        }
        case(COM_GPIB_ECAP):
        {
            return "IEEE488: No capability for intended operation";
        }
        case(COM_GPIB_EFSO):
        {
            return "IEEE488: File system operation error";
        }
        case(COM_GPIB_EBUS):
        {
            return "IEEE488: Command error during device call";
        }
        case(COM_GPIB_ESTB):
        {
            return "IEEE488: Serial poll-status byte lost";
        }
        case(COM_GPIB_ESRQ):
        {
            return "IEEE488: SRQ remains asserted";
        }
        case(COM_GPIB_ETAB):
        {
            return "IEEE488: Return buffer full";
        }
        case(COM_GPIB_ELCK):
        {
            return "IEEE488: Address or board locked";
        }
        case(COM_RS_INVALID_DATA_BITS):
        {
            return "RS-232: 5 data bits with 2 stop bits is an invalid combination, as is 6, 7, or 8 data bits with 1.5 stop bits";
        }
        case(COM_ERROR_RS_SETTINGS):
        {
            return "RS-232: Error configuring the COM port";
        }
        case(COM_INTERNAL_RESOURCES_ERROR):
        {
            return "Error dealing with internal system resources (events, threads, ...)";
        }
        case(COM_DLL_FUNC_ERROR):
        {
            return "A DLL or one of the required functions could not be loaded";
        }
        case(COM_FTDIUSB_INVALID_HANDLE):
        {
            return "FTDIUSB: invalid handle";
        }
        case(COM_FTDIUSB_DEVICE_NOT_FOUND):
        {
            return "FTDIUSB: device not found";
        }
        case(COM_FTDIUSB_DEVICE_NOT_OPENED):
        {
            return "FTDIUSB: device not opened";
        }
        case(COM_FTDIUSB_IO_ERROR):
        {
            return "FTDIUSB: IO error";
        }
        case(COM_FTDIUSB_INSUFFICIENT_RESOURCES):
        {
            return "FTDIUSB: insufficient resources";
        }
        case(COM_FTDIUSB_INVALID_PARAMETER):
        {
            return "FTDIUSB: invalid parameter";
        }
        case(COM_FTDIUSB_INVALID_BAUD_RATE):
        {
            return "FTDIUSB: invalid baud rate";
        }
        case(COM_FTDIUSB_DEVICE_NOT_OPENED_FOR_ERASE):
        {
            return "FTDIUSB: device not opened for erase";
        }
        case(COM_FTDIUSB_DEVICE_NOT_OPENED_FOR_WRITE):
        {
            return "FTDIUSB: device not opened for write";
        }
        case(COM_FTDIUSB_FAILED_TO_WRITE_DEVICE):
        {
            return "FTDIUSB: failed to write device";
        }
        case(COM_FTDIUSB_EEPROM_READ_FAILED):
        {
            return "FTDIUSB: EEPROM read failed";
        }
        case(COM_FTDIUSB_EEPROM_WRITE_FAILED):
        {
            return "FTDIUSB: EEPROM write failed";
        }
        case(COM_FTDIUSB_EEPROM_ERASE_FAILED):
        {
            return "FTDIUSB: EEPROM erase failed";
        }
        case(COM_FTDIUSB_EEPROM_NOT_PRESENT):
        {
            return "FTDIUSB: EEPROM not present";
        }
        case(COM_FTDIUSB_EEPROM_NOT_PROGRAMMED):
        {
            return "FTDIUSB: EEPROM not programmed";
        }
        case(COM_FTDIUSB_INVALID_ARGS):
        {
            return "FTDIUSB: invalid arguments";
        }
        case(COM_FTDIUSB_NOT_SUPPORTED):
        {
            return "FTDIUSB: not supported";
        }
        case(COM_FTDIUSB_OTHER_ERROR):
        {
            return "FTDIUSB: other error";
        }
        case(COM_PORT_ALREADY_OPEN):
        {
            return "Error while opening the COM port: was already open";
        }
        case(COM_PORT_CHECKSUM_ERROR):
        {
            return "Checksum error in received data from COM port";
        }
        case(COM_SOCKET_NOT_READY):
        {
            return "Socket not ready, you should call the function again";
        }
        case(COM_SOCKET_PORT_IN_USE):
        {
            return "Port is used by another socket";
        }
        case(COM_SOCKET_NOT_CONNECTED):
        {
            return "Socket not connected (or not valid)";
        }
        case(COM_SOCKET_TERMINATED):
        {
            return "Connection terminated (by peer)";
        }
        case(COM_SOCKET_NO_RESPONSE):
        {
            return "Can't connect to peer";
        }
        case(COM_SOCKET_INTERRUPTED):
        {
            return "Operation was interrupted by a nonblocked signal";
        }
        case(COM_PCI_INVALID_ID):
        {
            return "No Device with this ID is present";
        }
        case(COM_PCI_ACCESS_DENIED):
        {
            return "Driver could not be opened (on Vista: run as administrator!)";
        }
        case(COM_SOCKET_HOST_NOT_FOUND):
        {
            return "Host not found";
        }
        case(COM_DEVICE_CONNECTED):
        {
            return "Device already connected";
        }

///////////////////////////////////////////////////////////////////////////////
//
// Dll Errors - DLL errors occured in GCS DLL
//
///////////////////////////////////////////////////////////////////////////////

        case(PI_UNKNOWN_AXIS_IDENTIFIER):
        {
            return "Unknown axis identifier";
        }
        case(PI_NR_NAV_OUT_OF_RANGE):
        {
            return "Number for NAV out of range--must be in [1,10000]";
        }
        case(PI_INVALID_SGA):
        {
            return "Invalid value for SGA--must be one of {1, 10, 100, 1000}";
        }
        case(PI_UNEXPECTED_RESPONSE):
        {
            return "Controller sent unexpected response";
        }
        case(PI_NO_MANUAL_PAD):
        {
            return "No manual control pad installed, calls to SMA and related commands are not allowed";
        }
        case(PI_INVALID_MANUAL_PAD_KNOB):
        {
            return "Invalid number for manual control pad knob";
        }
        case(PI_INVALID_MANUAL_PAD_AXIS):
        {
            return "Axis not currently controlled by a manual control pad";
        }
        case(PI_CONTROLLER_BUSY):
        {
            return "Controller is busy with some lengthy operation (e.g. reference move, fast scan algorithm)";
        }
        case(PI_THREAD_ERROR):
        {
            return "Internal error--could not start thread";
        }
        case(PI_IN_MACRO_MODE):
        {
            return "Controller is (already) in macro mode--command not valid in macro mode";
        }
        case(PI_NOT_IN_MACRO_MODE):
        {
            return "Controller not in macro mode--command not valid unless macro mode active";
        }
        case(PI_MACRO_FILE_ERROR):
        {
            return "Could not open file to write or read macro";
        }
        case(PI_NO_MACRO_OR_EMPTY):
        {
            return "No macro with given name on controller, or macro is empty";
        }
        case(PI_MACRO_EDITOR_ERROR):
        {
            return "Internal error in macro editor";
        }
        case(PI_INVALID_ARGUMENT):
        {
            return "One or more arguments given to function is invalid (empty string, index out of range, ...)";
        }
        case(PI_AXIS_ALREADY_EXISTS):
        {
            return "Axis identifier is already in use by a connected stage";
        }
        case(PI_INVALID_AXIS_IDENTIFIER):
        {
            return "Invalid axis identifier";
        }
        case(PI_COM_ARRAY_ERROR):
        {
            return "Could not access array data in COM server";
        }
        case(PI_COM_ARRAY_RANGE_ERROR):
        {
            return "Range of array does not fit the number of parameters";
        }
        case(PI_INVALID_SPA_CMD_ID):
        {
            return "Invalid parameter ID given to SPA or SPA?";
        }
        case(PI_NR_AVG_OUT_OF_RANGE):
        {
            return "Number for AVG out of range--must be >0";
        }
        case(PI_WAV_SAMPLES_OUT_OF_RANGE):
        {
            return "Incorrect number of samples given to WAV";
        }
        case(PI_WAV_FAILED):
        {
            return "Generation of wave failed";
        }
        case(PI_MOTION_ERROR):
        {
            return "Motion error: position error too large, servo is switched off automatically";
        }
        case(PI_RUNNING_MACRO):
        {
            return "Controller is (already) running a macro";
        }
        case(PI_PZT_CONFIG_FAILED):
        {
            return "Configuration of PZT stage or amplifier failed";
        }
        case(PI_PZT_CONFIG_INVALID_PARAMS):
        {
            return "Current settings are not valid for desired configuration";
        }
        case(PI_UNKNOWN_CHANNEL_IDENTIFIER):
        {
            return "Unknown channel identifier";
        }
        case(PI_WAVE_PARAM_FILE_ERROR):
        {
            return "Error while reading/writing wave generator parameter file";
        }
        case(PI_UNKNOWN_WAVE_SET):
        {
            return "Could not find description of wave form. Maybe WG.INI is missing?";
        }
        case(PI_WAVE_EDITOR_FUNC_NOT_LOADED):
        {
            return "The WGWaveEditor DLL function was not found at startup";
        }
        case(PI_USER_CANCELLED):
        {
            return "The user cancelled a dialog";
        }
        case(PI_C844_ERROR):
        {
            return "Error from C-844 Controller";
        }
        case(PI_DLL_NOT_LOADED):
        {
            return "DLL necessary to call function not loaded, or function not found in DLL";
        }
        case(PI_PARAMETER_FILE_PROTECTED):
        {
            return "The open parameter file is protected and cannot be edited";
        }
        case(PI_NO_PARAMETER_FILE_OPENED):
        {
            return "There is no parameter file open";
        }
        case(PI_STAGE_DOES_NOT_EXIST):
        {
            return "Selected stage does not exist";
        }
        case(PI_PARAMETER_FILE_ALREADY_OPENED):
        {
            return "There is already a parameter file open. Close it before opening a new file";
        }
        case(PI_PARAMETER_FILE_OPEN_ERROR):
        {
            return "Could not open parameter file";
        }
        case(PI_INVALID_CONTROLLER_VERSION):
        {
            return "The version of the connected controller is invalid";
        }
        case(PI_PARAM_SET_ERROR):
        {
            return "Parameter could not be set with SPA--parameter not defined for this controller!";
        }
        case(PI_NUMBER_OF_POSSIBLE_WAVES_EXCEEDED):
        {
            return "The maximum number of wave definitions has been exceeded";
        }
        case(PI_NUMBER_OF_POSSIBLE_GENERATORS_EXCEEDED):
        {
            return "The maximum number of wave generators has been exceeded";
        }
        case(PI_NO_WAVE_FOR_AXIS_DEFINED):
        {
            return "No wave defined for specified axis";
        }
        case(PI_CANT_STOP_OR_START_WAV):
        {
            return "Wave output to axis already stopped/started";
        }
        case(PI_REFERENCE_ERROR):
        {
            return "Not all axes could be referenced";
        }
        case(PI_REQUIRED_WAVE_NOT_FOUND):
        {
            return "Could not find parameter set required by frequency relation";
        }
        case(PI_INVALID_SPP_CMD_ID):
        {
            return "Command ID given to SPP or SPP? is not valid";
        }
        case(PI_STAGE_NAME_ISNT_UNIQUE):
        {
            return "A stage name given to CST is not unique";
        }
        case(PI_FILE_TRANSFER_BEGIN_MISSING):
        {
            return "A uuencoded file transfered did not start with \"begin\" followed by the proper filename";
        }
        case(PI_FILE_TRANSFER_ERROR_TEMP_FILE):
        {
            return "Could not create/read file on host PC";
        }
        case(PI_FILE_TRANSFER_CRC_ERROR):
        {
            return "Checksum error when transfering a file to/from the controller";
        }
        case(PI_COULDNT_FIND_PISTAGES_DAT):
        {
            return "The PiStages.dat database could not be found. This file is required to connect a stage with the CST command";
        }
        case(PI_NO_WAVE_RUNNING):
        {
            return "No wave being output to specified axis";
        }
        case(PI_INVALID_PASSWORD):
        {
            return "Invalid password";
        }
        case(PI_OPM_COM_ERROR):
        {
            return "Error during communication with OPM (Optical Power Meter), maybe no OPM connected";
        }
        case(I_WAVE_EDITOR_WRONG_PARAMNUM):
        {
            return "WaveEditor: Error during wave creation, incorrect number of parameters";
        }
        case(I_WAVE_EDITOR_FREQUENCY_OUT_OF_RANGE):
        {
            return "WaveEditor: Frequency out of range";
        }
        case(I_WAVE_EDITOR_WRONG_IP_VALUE):
        {
            return "WaveEditor: Error during wave creation, incorrect index for integer parameter";
        }
        case(I_WAVE_EDITOR_WRONG_DP_VALUE):
        {
            return "WaveEditor: Error during wave creation, incorrect index for floating point parameter";
        }
        case(I_WAVE_EDITOR_WRONG_ITEM_VALUE):
        {
            return "WaveEditor: Error during wave creation, could not calculate value";
        }
        case(I_WAVE_EDITOR_MISSING_GRAPH_COMPONENT):
        {
            return "WaveEditor: Graph display component not installed";
        }
        case(PI_EXT_PROFILE_UNALLOWED_CMD):
        {
            return "User Profile Mode: Command is not allowed, check for required preparatory commands";
        }
        case(PI_EXT_PROFILE_EXPECTING_MOTION_ERROR):
        {
            return "User Profile Mode: First target position in User Profile is too far from current position";
        }
        case(PI_EXT_PROFILE_ACTIVE):
        {
            return "Controller is (already) in User Profile Mode";
        }
        case(PI_EXT_PROFILE_INDEX_OUT_OF_RANGE):
        {
            return "User Profile Mode: Block or Data Set index out of allowed range";
        }
        case(PI_PROFILE_GENERATOR_NO_PROFILE):
        {
            return "ProfileGenerator: No profile has been created yet";
        }
        case(PI_PROFILE_GENERATOR_OUT_OF_LIMITS):
        {
            return "ProfileGenerator: Generated profile exceeds limits of one or both axes";
        }
        case(PI_PROFILE_GENERATOR_UNKNOWN_PARAMETER):
        {
            return "ProfileGenerator: Unknown parameter ID in Set/Get Parameter command";
        }
        case(PI_PROFILE_GENERATOR_PAR_OUT_OF_RANGE):
        {
            return "ProfileGenerator: Parameter out of allowed range";
        }
        case(PI_EXT_PROFILE_OUT_OF_MEMORY):
        {
            return "User Profile Mode: Out of memory";
        }
        case(PI_EXT_PROFILE_WRONG_CLUSTER):
        {
            return "User Profile Mode: Cluster is not assigned to this axis";
        }
        case(PI_EXT_PROFILE_UNKNOWN_CLUSTER_IDENTIFIER):
        {
            return "Unknown cluster identifier";
        }
        case(PI_INVALID_DEVICE_DRIVER_VERSION):
        {
            return "The installed device driver doesn't match the required version. Please see the documentation to determine the required device driver version.";
        }
        case(PI_INVALID_LIBRARY_VERSION):
        {
            return "The library used doesn't match the required version. Please see the documentation to determine the required library version.";
        }
        case(PI_INTERFACE_LOCKED):
        {
            return "The interface is currently locked by another function. Please try again later.";
        }
        case(PI_PARAM_DAT_FILE_INVALID_VERSION):
        {
            return "Version of parameter DAT file does not match the required version. Current files are available at www.pi.ws.";
        }
        case(PI_CANNOT_WRITE_TO_PARAM_DAT_FILE):
        {
            return "Cannot write to parameter DAT file to store user defined stage type.";
        }
        case(PI_CANNOT_CREATE_PARAM_DAT_FILE):
        {
            return "Cannot create parameter DAT file to store user defined stage type.";
        }
        case(PI_PARAM_DAT_FILE_INVALID_REVISION):
        {
            return "Parameter DAT file does not have correct revision.";
        }
        case(PI_USERSTAGES_DAT_FILE_INVALID_REVISION):
        {
            return "User stages DAT file does not have correct revision.";
        }
        case(PI_SOFTWARE_TIMEOUT):
        {
            return "Timeout Error. Some lengthy operation did not finish within expected time.";
        }
        case(PI_WRONG_DATA_TYPE):
        {
            return "A function argument has an unexpected datatype.";
        }
        case(PI_DIFFERENT_ARRAY_SIZES):
        {
            return "Length of data arrays is different.";
        }
        case(PI_PARAM_NOT_FOUND_IN_PARAM_DAT_FILE):
        {
            return "Parameter value not found in parameter DAT file.";
        }
        case(PI_MACRO_RECORDING_NOT_ALLOWED_IN_THIS_MODE):
        {
            return "Macro recording is not allowed in this mode of operation.";
        }
        case(PI_USER_CANCELLED_COMMAND):
        {
            return "command cancelled by user input.";
        }
        case(PI_TOO_FEW_GCS_DATA):
        {
            return "Controller sent too few GCS data sets";
        }
        case(PI_TOO_MANY_GCS_DATA):
        {
            return "Controller sent too many GCS data sets";
        }
        case(PI_GCS_DATA_READ_ERROR):
        {
            return "Communication error while reading GCS data";
        }
        case(PI_WRONG_NUMBER_OF_INPUT_ARGUMENTS):
        {
            return "Wrong number of input arguments.";
        }
        case(PI_FAILED_TO_CHANGE_CCL_LEVEL):
        {
            return "Change of command level has failed.";
        }
        case(PI_FAILED_TO_SWITCH_OFF_SERVO):
        {
            return "Switching off the servo mode has failed.";
        }
        case(PI_FAILED_TO_SET_SINGLE_PARAMETER_WHILE_PERFORMING_CST):
        {
            return "A parameter could not be set while performing CST: CST was not performed (parameters remain unchanged).";
        }
        case(PI_ERROR_CONTROLLER_REBOOT):
        {
            return "Connection could not be reestablished after reboot.";
        }
        case(PI_ERROR_AT_QHPA):
        {
            return "Sending HPA? or receiving the response has failed.";
        }
        case(PI_QHPA_NONCOMPLIANT_WITH_GCS):
        {
            return "HPA? response does not comply with GCS2 syntax.";
        }
        case(PI_FAILED_TO_READ_QSPA):
        {
            return "Response to SPA? could not be received.";
        }
        case(PI_PAM_FILE_WRONG_VERSION):
        {
            return "Version of PAM file cannot be handled (too old or too new)";
        }
        case(PI_PAM_FILE_INVALID_FORMAT):
        {
            return "PAM file does not contain required data in PAM-file format";
        }
        case(PI_INCOMPLETE_INFORMATION):
        {
            return "Information does not contain all required data";
        }
        case(PI_NO_VALUE_AVAILABLE):
        {
            return "No value for parameter available";
        }
        case(PI_NO_PAM_FILE_OPEN):
        {
            return "No PAM file is open";
        }
        case(PI_INVALID_VALUE):
        {
            return "Invalid value";
        }
        case(PI_UNKNOWN_PARAMETER):
        {
            return "Unknown parameter";
        }
        case(PI_RESPONSE_TO_QSEP_FAILED):
        {
            return "Response to SEP? could not be received.";
        }
        case(PI_RESPONSE_TO_QSPA_FAILED):
        {
            return "Response to SPA? could not be received.";
        }
        case(PI_ERROR_IN_CST_VALIDATION):
        {
            return "Error while performing CST: One or more parameters were not set correctly.";
        }
        case(PI_ERROR_PAM_FILE_HAS_DUPLICATE_ENTRY_WITH_DIFFERENT_VALUES):
        {
            return "PAM file has duplicate entry with different values.";
        }
        case(PI_ERROR_FILE_NO_SIGNATURE):
        {
            return "File has no signature";
        }
        case(PI_ERROR_FILE_INVALID_SIGNATURE):
        {
            return "File has invalid signature";
        }
        case(PI_ERROR_CANNOT_DETERMINE_ACTUAL_END_OF_TRAVEL_WHILE_PLATFORM_IS_MOVING):
        {
            return "Cannot determine actual end of travel range while platform is moving.";
        }
        case(PI_ERROR_AT_QIDN):
        {
            return "Sending IDN? or receiving the response has failed.";
        }
        case(PI_ERROR_AT_MAC_DEF):
        {
            return "Sending MAC_DEF or receiving the response has failed.";
        }
        case(PI_CONTROLLER_OR_CONTROLLER_VERSION_DOES_NOT_EXIST_IN_PISTAGES_DATABASE):
        {
            return "Sending Controller or controller version does not exist in PIStages database.";
        }
        case(PI_NOT_ENOUGH_MEMORY):
        {
            return "Not enough memory";
        }
        case(PI_ERROR_AXIS_RUNTIME_ERROR):
        {
            return "Runtime error indicated for axis, check error log with \"LOG?\" to find more details.";
        }
        case(PI_ERROR_SYSTEM_RUNTIME_CRITICAL_ERROR):
        {
            return "Critical error indicated for system, check error log with \"LOG?\" to find more details.";
        }
        case(PI_PARAMETER_DB_INVALID_STAGE_TYPE_FORMAT):
        {
            return "PI stage database: String containing stage type and description has invalid format.";
        }
        case(PI_PARAMETER_DB_SYSTEM_NOT_AVAILABLE):
        {
            return "PI stage database: Database does not contain the selected stage type for the connected controller.";
        }
        case(PI_PARAMETER_DB_FAILED_TO_ESTABLISH_CONNECTION):
        {
            return "PI stage database: Establishing the connection has failed.";
        }
        case(PI_PARAMETER_DB_COMMUNICATION_ERROR):
        {
            return "PI stage database: Communication was interrupted (e.g. because database was deleted).";
        }
        case(PI_PARAMETER_DB_ERROR_WHILE_QUERYING_PARAMETERS):
        {
            return "PI stage database: Querying data failed.";
        }
        case(PI_PARAMETER_DB_SYSTEM_ALREADY_EXISTS):
        {
            return "PI stage database: System already exists. Rename stage and try again.";
        }
        case(PI_PARAMETER_DB_QHPA_CONTANS_UNKNOWN_PAM_IDS):
        {
            return "PI stage database: Response to HPA? contains unknown parameter IDs.";
        }
        case(PI_PARAMETER_DB_AND_QHPA_ARE_INCONSISTENT):
        {
            return "PI stage database: Inconsistency between database and response to HPA?.";
        }
        case(PI_PARAMETER_DB_SYSTEM_COULD_NOT_BE_ADDED):
        {
            return "PI stage database: Stage has not been added.";
        }
        case(PI_PARAMETER_DB_SYSTEM_COULD_NOT_BE_REMOVED):
        {
            return "PI stage database: Stage has not been removed.";
        }
        case(PI_PARAMETER_DB_CONTROLLER_DB_PARAMETERS_MISMATCH):
        {
            return "Controller does not support all stage parameters stored in PI stage database. No parameters were set.";
        }
        case(PI_PARAMETER_DB_DATABASE_IS_OUTDATED):
        {
            return "The version of PISTAGES3.DB stage database is out of date. Please update via PIUpdateFinder. No parameters were set.";
        }
        case(PI_PARAMETER_DB_AND_HPA_MISMATCH_STRICT):
        {
            return "Mismatch between number of parameters present in stage database and available in controller interface. No parameters were set.";
        }
        case(PI_PARAMETER_DB_AND_HPA_MISMATCH_LOOSE):
        {
            return "Mismatch between number of parameters present in stage database and available in controller interface. Some parameters were ignored.";
        }
        case(PI_PARAMETER_DB_FAILED_TO_SET_PARAMETERS_CORRECTLY):
        {
            return "One or more parameters could not be set correctly on the controller.";
        }
        case(PI_PARAMETER_DB_MISSING_PARAMETER_DEFINITIONS_IN_DATABASE):
        {
            return "One or more parameter definitions are not present in stage database. Please update PISTAGES3.DB via PIUpdateFinder. Missing parameters were ignored.";
        }
        case(PI_PARAMETER_DB_MISSING_FIRMWARE_FEATURE_ON_CONTROLLER):
        {
            return "Parameters could not be set on controller because the corresponding firmware feature is missing";
        }

///////////////////////////////////////////////////////////////////////////////
//
// Controller Errors - Errors set by the controller or the GCS DLL
//
///////////////////////////////////////////////////////////////////////////////

        case(PI_CNTR_NO_ERROR):
        {
            return "No error";
        }
        case(PI_CNTR_PARAM_SYNTAX):
        {
            return "Parameter syntax error";
        }
        case(PI_CNTR_UNKNOWN_COMMAND):
        {
            return "Unknown command";
        }
        case(PI_CNTR_COMMAND_TOO_LONG):
        {
            return "Command length out of limits or command buffer overrun";
        }
        case(PI_CNTR_SCAN_ERROR):
        {
            return "Error while scanning";
        }
        case(PI_CNTR_MOVE_WITHOUT_REF_OR_NO_SERVO):
        {
            return "Unallowable move attempted on unreferenced axis, or move attempted with servo off";
        }
        case(PI_CNTR_INVALID_SGA_PARAM):
        {
            return "Parameter for SGA not valid";
        }
        case(PI_CNTR_POS_OUT_OF_LIMITS):
        {
            return "Position out of limits";
        }
        case(PI_CNTR_VEL_OUT_OF_LIMITS):
        {
            return "Velocity out of limits";
        }
        case(PI_CNTR_SET_PIVOT_NOT_POSSIBLE):
        {
            return "Attempt to set pivot point while U,V and W not all 0";
        }
        case(PI_CNTR_STOP):
        {
            return "Controller was stopped by command";
        }
        case(PI_CNTR_SST_OR_SCAN_RANGE):
        {
            return "Parameter for SST or for one of the embedded scan algorithms out of range";
        }
        case(PI_CNTR_INVALID_SCAN_AXES):
        {
            return "Invalid axis combination for fast scan";
        }
        case(PI_CNTR_INVALID_NAV_PARAM):
        {
            return "Parameter for NAV out of range";
        }
        case(PI_CNTR_INVALID_ANALOG_INPUT):
        {
            return "Invalid analog channel";
        }
        case(PI_CNTR_INVALID_AXIS_IDENTIFIER):
        {
            return "Invalid axis identifier";
        }
        case(PI_CNTR_INVALID_STAGE_NAME):
        {
            return "Invalid stage name";
        }
        case(PI_CNTR_PARAM_OUT_OF_RANGE):
        {
            return "Parameter out of range";
        }
        case(PI_CNTR_INVALID_MACRO_NAME):
        {
            return "Invalid macro name";
        }
        case(PI_CNTR_MACRO_RECORD):
        {
            return "Error while recording macro";
        }
        case(PI_CNTR_MACRO_NOT_FOUND):
        {
            return "Macro not found";
        }
        case(PI_CNTR_AXIS_HAS_NO_BRAKE):
        {
            return "Axis has no brake";
        }
        case(PI_CNTR_DOUBLE_AXIS):
        {
            return "Axis identifier specified more than once";
        }
        case(PI_CNTR_ILLEGAL_AXIS):
        {
            return "Illegal axis or channel";
        }
        case(PI_CNTR_PARAM_NR):
        {
            return "Incorrect number of parameters";
        }
        case(PI_CNTR_INVALID_REAL_NR):
        {
            return "Invalid floating point number";
        }
        case(PI_CNTR_MISSING_PARAM):
        {
            return "Parameter missing";
        }
        case(PI_CNTR_SOFT_LIMIT_OUT_OF_RANGE):
        {
            return "Soft limit out of range";
        }
        case(PI_CNTR_NO_MANUAL_PAD):
        {
            return "No manual pad found";
        }
        case(PI_CNTR_NO_JUMP):
        {
            return "No more step-response values";
        }
        case(PI_CNTR_INVALID_JUMP):
        {
            return "No step-response values recorded";
        }
        case(PI_CNTR_AXIS_HAS_NO_REFERENCE):
        {
            return "Axis has no reference sensor";
        }
        case(PI_CNTR_STAGE_HAS_NO_LIM_SWITCH):
        {
            return "Axis has no limit switch";
        }
        case(PI_CNTR_NO_RELAY_CARD):
        {
            return "No relay card installed";
        }
        case(PI_CNTR_CMD_NOT_ALLOWED_FOR_STAGE):
        {
            return "Command not allowed for selected stage(s)";
        }
        case(PI_CNTR_NO_DIGITAL_INPUT):
        {
            return "No digital input installed";
        }
        case(PI_CNTR_NO_DIGITAL_OUTPUT):
        {
            return "No digital output configured";
        }
        case(PI_CNTR_NO_MCM):
        {
            return "No more MCM responses";
        }
        case(PI_CNTR_INVALID_MCM):
        {
            return "No MCM values recorded";
        }
        case(PI_CNTR_INVALID_CNTR_NUMBER):
        {
            return "Controller number invalid";
        }
        case(PI_CNTR_NO_JOYSTICK_CONNECTED):
        {
            return "No joystick configured";
        }
        case(PI_CNTR_INVALID_EGE_AXIS):
        {
            return "Invalid axis for electronic gearing, axis can not be slave";
        }
        case(PI_CNTR_SLAVE_POSITION_OUT_OF_RANGE):
        {
            return "Position of slave axis is out of range";
        }
        case(PI_CNTR_COMMAND_EGE_SLAVE):
        {
            return "Slave axis cannot be commanded directly when electronic gearing is enabled";
        }
        case(PI_CNTR_JOYSTICK_CALIBRATION_FAILED):
        {
            return "Calibration of joystick failed";
        }
        case(PI_CNTR_REFERENCING_FAILED):
        {
            return "Referencing failed";
        }
        case(PI_CNTR_OPM_MISSING):
        {
            return "OPM (Optical Power Meter) missing";
        }
        case(PI_CNTR_OPM_NOT_INITIALIZED):
        {
            return "OPM (Optical Power Meter) not initialized or cannot be initialized";
        }
        case(PI_CNTR_OPM_COM_ERROR):
        {
            return "OPM (Optical Power Meter) Communication Error";
        }
        case(PI_CNTR_MOVE_TO_LIMIT_SWITCH_FAILED):
        {
            return "Move to limit switch failed";
        }
        case(PI_CNTR_REF_WITH_REF_DISABLED):
        {
            return "Attempt to reference axis with referencing disabled";
        }
        case(PI_CNTR_AXIS_UNDER_JOYSTICK_CONTROL):
        {
            return "Selected axis is controlled by joystick";
        }
        case(PI_CNTR_COMMUNICATION_ERROR):
        {
            return "Controller detected communication error";
        }
        case(PI_CNTR_DYNAMIC_MOVE_IN_PROCESS):
        {
            return "Command is not allowed while the affected axis is in motion.";
        }
        case(PI_CNTR_UNKNOWN_PARAMETER):
        {
            return "Unknown parameter";
        }
        case(PI_CNTR_NO_REP_RECORDED):
        {
            return "No commands were recorded with REP";
        }
        case(PI_CNTR_INVALID_PASSWORD):
        {
            return "Password invalid";
        }
        case(PI_CNTR_INVALID_RECORDER_CHAN):
        {
            return "Data recorder table does not exist";
        }
        case(PI_CNTR_INVALID_RECORDER_SRC_OPT):
        {
            return "Source option does not exist; number too low or too high";
        }
        case(PI_CNTR_INVALID_RECORDER_SRC_CHAN):
        {
            return "Source ID (channel or axis) too low or too high";
        }
        case(PI_CNTR_PARAM_PROTECTION):
        {
            return "Protected Param: current Command Level (CCL) too low";
        }
        case(PI_CNTR_AUTOZERO_RUNNING):
        {
            return "Command execution not possible while Autozero is running";
        }
        case(PI_CNTR_NO_LINEAR_AXIS):
        {
            return "Autozero requires at least one linear axis";
        }
        case(PI_CNTR_INIT_RUNNING):
        {
            return "Initialization still in progress";
        }
        case(PI_CNTR_READ_ONLY_PARAMETER):
        {
            return "Parameter is read-only";
        }
        case(PI_CNTR_PAM_NOT_FOUND):
        {
            return "Parameter not found in non-volatile memory";
        }
        case(PI_CNTR_VOL_OUT_OF_LIMITS):
        {
            return "Voltage out of limits";
        }
        case(PI_CNTR_WAVE_TOO_LARGE):
        {
            return "Not enough memory available for requested wave curve";
        }
        case(PI_CNTR_NOT_ENOUGH_DDL_MEMORY):
        {
            return "Not enough memory available for DDL table; DDL can not be started";
        }
        case(PI_CNTR_DDL_TIME_DELAY_TOO_LARGE):
        {
            return "Time delay larger than DDL table; DDL can not be started";
        }
        case(PI_CNTR_DIFFERENT_ARRAY_LENGTH):
        {
            return "The requested arrays have different lengths; query them separately";
        }
        case(PI_CNTR_GEN_SINGLE_MODE_RESTART):
        {
            return "Attempt to restart the generator while it is running in single step mode";
        }
        case(PI_CNTR_ANALOG_TARGET_ACTIVE):
        {
            return "Motion commands and wave generator activation are not allowed when analog target is active";
        }
        case(PI_CNTR_WAVE_GENERATOR_ACTIVE):
        {
            return "Motion commands are not allowed when wave generator output is active; use WGO to disable generator output";
        }
        case(PI_CNTR_AUTOZERO_DISABLED):
        {
            return "No sensor channel or no piezo channel connected to selected axis (sensor and piezo matrix)";
        }
        case(PI_CNTR_NO_WAVE_SELECTED):
        {
            return "Generator started (WGO) without having selected a wave table (WSL).";
        }
        case(PI_CNTR_IF_BUFFER_OVERRUN):
        {
            return "Interface buffer did overrun and command couldn't be received correctly";
        }
        case(PI_CNTR_NOT_ENOUGH_RECORDED_DATA):
        {
            return "Data Record Table does not hold enough recorded data";
        }
        case(PI_CNTR_TABLE_DEACTIVATED):
        {
            return "Data Record Table is not configured for recording";
        }
        case(PI_CNTR_OPENLOOP_VALUE_SET_WHEN_SERVO_ON):
        {
            return "Open-loop commands are not allowed when servo is on";
        }
        case(PI_CNTR_RAM_ERROR):
        {
            return "Hardware error affecting RAM";
        }
        case(PI_CNTR_MACRO_UNKNOWN_COMMAND):
        {
            return "Not macro command";
        }
        case(PI_CNTR_MACRO_PC_ERROR):
        {
            return "Macro counter out of range";
        }
        case(PI_CNTR_JOYSTICK_ACTIVE):
        {
            return "Joystick is active";
        }
        case(PI_CNTR_MOTOR_IS_OFF):
        {
            return "Motor is off";
        }
        case(PI_CNTR_ONLY_IN_MACRO):
        {
            return "Macro-only command";
        }
        case(PI_CNTR_JOYSTICK_UNKNOWN_AXIS):
        {
            return "Invalid joystick axis";
        }
        case(PI_CNTR_JOYSTICK_UNKNOWN_ID):
        {
            return "Joystick unknown";
        }
        case(PI_CNTR_REF_MODE_IS_ON):
        {
            return "Move without referenced stage";
        }
        case(PI_CNTR_NOT_ALLOWED_IN_CURRENT_MOTION_MODE):
        {
            return "Command not allowed in current motion mode";
        }
        case(PI_CNTR_DIO_AND_TRACING_NOT_POSSIBLE):
        {
            return "No tracing possible while digital IOs are used on this HW revision. Reconnect to switch operation mode.";
        }
        case(PI_CNTR_COLLISION):
        {
            return "Move not possible, would cause collision";
        }
        case(PI_CNTR_SLAVE_NOT_FAST_ENOUGH):
        {
            return "Stage is not capable of following the master. Check the gear ratio(SRA).";
        }
        case(PI_CNTR_CMD_NOT_ALLOWED_WHILE_AXIS_IN_MOTION):
        {
            return "This command is not allowed while the affected axis or its master is in motion.";
        }
        case(PI_CNTR_OPEN_LOOP_JOYSTICK_ENABLED):
        {
            return "Servo cannot be switched on when open-loop joystick control is enabled.";
        }
        case(PI_CNTR_INVALID_SERVO_STATE_FOR_PARAMETER):
        {
            return "This parameter cannot be changed in current servo mode.";
        }
        case(PI_CNTR_UNKNOWN_STAGE_NAME):
        {
            return "Unknown stage name";
        }
        case(PI_CNTR_INVALID_VALUE_LENGTH):
        {
            return "Invalid length of value (too much characters)";
        }
        case(PI_CNTR_AUTOZERO_FAILED):
        {
            return "AutoZero procedure was not successful";
        }
        case(PI_CNTR_SENSOR_VOLTAGE_OFF):
        {
            return "Sensor voltage is off";
        }
        case(PI_LABVIEW_ERROR):
        {
            return "PI LabVIEW driver reports error. See source control for details.";
        }
        case(PI_CNTR_NO_AXIS):
        {
            return "No stage connected to axis";
        }
        case(PI_CNTR_NO_AXIS_PARAM_FILE):
        {
            return "File with axis parameters not found";
        }
        case(PI_CNTR_INVALID_AXIS_PARAM_FILE):
        {
            return "Invalid axis parameter file";
        }
        case(PI_CNTR_NO_AXIS_PARAM_BACKUP):
        {
            return "Backup file with axis parameters not found";
        }
        case(PI_CNTR_RESERVED_204):
        {
            return "PI internal error code 204";
        }
        case(PI_CNTR_SMO_WITH_SERVO_ON):
        {
            return "SMO with servo on";
        }
        case(PI_CNTR_UUDECODE_INCOMPLETE_HEADER):
        {
            return "uudecode: incomplete header";
        }
        case(PI_CNTR_UUDECODE_NOTHING_TO_DECODE):
        {
            return "uudecode: nothing to decode";
        }
        case(PI_CNTR_UUDECODE_ILLEGAL_FORMAT):
        {
            return "uudecode: illegal UUE format";
        }
        case(PI_CNTR_CRC32_ERROR):
        {
            return "CRC32 error";
        }
        case(PI_CNTR_ILLEGAL_FILENAME):
        {
            return "Illegal file name (must be 8-0 format)";
        }
        case(PI_CNTR_FILE_NOT_FOUND):
        {
            return "File not found on controller";
        }
        case(PI_CNTR_FILE_WRITE_ERROR):
        {
            return "Error writing file on controller";
        }
        case(PI_CNTR_DTR_HINDERS_VELOCITY_CHANGE):
        {
            return "VEL command not allowed in DTR Command Mode";
        }
        case(PI_CNTR_POSITION_UNKNOWN):
        {
            return "Position calculations failed";
        }
        case(PI_CNTR_CONN_POSSIBLY_BROKEN):
        {
            return "The connection between controller and stage may be broken";
        }
        case(PI_CNTR_ON_LIMIT_SWITCH):
        {
            return "The connected stage has driven into a limit switch, some controllers need CLR to resume operation";
        }
        case(PI_CNTR_UNEXPECTED_STRUT_STOP):
        {
            return "Strut test command failed because of an unexpected strut stop";
        }
        case(PI_CNTR_POSITION_BASED_ON_ESTIMATION):
        {
            return "While MOV! is running position can only be estimated!";
        }
        case(PI_CNTR_POSITION_BASED_ON_INTERPOLATION):
        {
            return "Position was calculated during MOV motion";
        }
        case(PI_CNTR_INTERPOLATION_FIFO_UNDERRUN):
        {
            return "FIFO buffer underrun during interpolation";
        }
        case(PI_CNTR_INTERPOLATION_FIFO_OVERFLOW):
        {
            return "FIFO buffer overflow during interpolation";
        }
        case(PI_CNTR_INVALID_HANDLE):
        {
            return "Invalid handle";
        }
        case(PI_CNTR_NO_BIOS_FOUND):
        {
            return "No bios found";
        }
        case(PI_CNTR_SAVE_SYS_CFG_FAILED):
        {
            return "Save system configuration failed";
        }
        case(PI_CNTR_LOAD_SYS_CFG_FAILED):
        {
            return "Load system configuration failed";
        }
        case(PI_CNTR_SEND_BUFFER_OVERFLOW):
        {
            return "Send buffer overflow";
        }
        case(PI_CNTR_VOLTAGE_OUT_OF_LIMITS):
        {
            return "Voltage out of limits";
        }
        case(PI_CNTR_OPEN_LOOP_MOTION_SET_WHEN_SERVO_ON):
        {
            return "Open-loop motion attempted when servo ON";
        }
        case(PI_CNTR_RECEIVING_BUFFER_OVERFLOW):
        {
            return "Received command is too long";
        }
        case(PI_CNTR_EEPROM_ERROR):
        {
            return "Error while reading/writing EEPROM";
        }
        case(PI_CNTR_I2C_ERROR):
        {
            return "Error on I2C bus";
        }
        case(PI_CNTR_RECEIVING_TIMEOUT):
        {
            return "Timeout while receiving command";
        }
        case(PI_CNTR_TIMEOUT):
        {
            return "A lengthy operation has not finished in the expected time";
        }
        case(PI_CNTR_MACRO_OUT_OF_SPACE):
        {
            return "Insufficient space to store macro";
        }
        case(PI_CNTR_EUI_OLDVERSION_CFGDATA):
        {
            return "Configuration data has old version number";
        }
        case(PI_CNTR_EUI_INVALID_CFGDATA):
        {
            return "Invalid configuration data";
        }
        case(PI_CNTR_HARDWARE_ERROR):
        {
            return "Internal hardware error";
        }
        case(PI_CNTR_WAV_INDEX_ERROR):
        {
            return "Wave generator index error";
        }
        case(PI_CNTR_WAV_NOT_DEFINED):
        {
            return "Wave table not defined";
        }
        case(PI_CNTR_WAV_TYPE_NOT_SUPPORTED):
        {
            return "Wave type not supported";
        }
        case(PI_CNTR_WAV_LENGTH_EXCEEDS_LIMIT):
        {
            return "Wave length exceeds limit";
        }
        case(PI_CNTR_WAV_PARAMETER_NR):
        {
            return "Wave parameter number error";
        }
        case(PI_CNTR_WAV_PARAMETER_OUT_OF_LIMIT):
        {
            return "Wave parameter out of range";
        }
        case(PI_CNTR_WGO_BIT_NOT_SUPPORTED):
        {
            return "WGO command bit not supported";
        }
        case(PI_CNTR_EMERGENCY_STOP_BUTTON_ACTIVATED):
        {
            return "The \"red knob\" is still set and disables system";
        }
        case(PI_CNTR_EMERGENCY_STOP_BUTTON_WAS_ACTIVATED):
        {
            return "The \"red knob\" was activated and still disables system - reanimation required";
        }
        case(PI_CNTR_REDUNDANCY_LIMIT_EXCEEDED):
        {
            return "Position consistency check failed";
        }
        case(PI_CNTR_COLLISION_SWITCH_ACTIVATED):
        {
            return "Hardware collision sensor(s) are activated";
        }
        case(PI_CNTR_FOLLOWING_ERROR):
        {
            return "Strut following error occurred, e.g. caused by overload or encoder failure";
        }
        case(PI_CNTR_SENSOR_SIGNAL_INVALID):
        {
            return "One sensor signal is not valid";
        }
        case(PI_CNTR_SERVO_LOOP_UNSTABLE):
        {
            return "Servo loop was unstable due to wrong parameter setting and switched off to avoid damage.";
        }
        case(PI_CNTR_LOST_SPI_SLAVE_CONNECTION):
        {
            return "digital connection to external spi slave device is lost";
        }
        case(PI_CNTR_MOVE_ATTEMPT_NOT_PERMITTED):
        {
            return "Move attempt not permitted due to customer or limit settings";
        }
        case(PI_CNTR_TRIGGER_EMERGENCY_STOP):
        {
            return "Emergency stop caused by trigger input";
        }
        case(PI_CNTR_CS_DOES_NOT_EXIST):
        {
            return "A command refers to a coordinate system that does not exist";
        }
        case(PI_CNTR_PARENT_CS_DOES_NOT_EXIST):
        {
            return "A command refers to a coordinate system that has no parent node";
        }
        case(PI_CNTR_CS_IN_USE):
        {
            return "Attempt to delete or change a coordinate system that is in use";
        }
        case(PI_CNTR_CS_DEFINITION_IS_CYCLIC):
        {
            return "Definition of a coordinate system is cyclic";
        }
        case(PI_CNTR_HEXAPOD_IN_MOTION):
        {
            return "Coordinate system cannot be defined as long as Hexapod is in motion";
        }
        case(PI_CNTR_CS_TYPE_CANNOT_BE_ENABLED):
        {
            return "Coordinate system type is not intended for manual enabling";
        }
        case(PI_CNTR_CS_PARENT_IDENTICAL_TO_CHILD):
        {
            return "A coordinate system cannot be linked to itself";
        }
        case(PI_CNTR_CS_DEFINITION_INCONSISTENT):
        {
            return "Coordinate system definition is erroneous or not complete (replace or delete it)";
        }
        case(PI_CNTR_CS_NOT_IN_SAME_CHAIN):
        {
            return "The coordinate systems are not part of the same chain";
        }
        case(PI_CNTR_CS_MEMORY_FULL):
        {
            return "Unused coordinate system must be deleted before new coordinate system can be stored";
        }
        case(PI_CNTR_SPI_COMMAND_NOT_SUPPORTED):
        {
            return "With this coordinate system type SPI usage is not supported";
        }
        case(PI_CNTR_SOFTLIMITS_INVALID):
        {
            return "Soft limits invalid due to changes in coordinate system";
        }
        case(PI_CNTR_CS_WRITE_PROTECTED):
        {
            return "Coordinate system is write protected";
        }
        case(PI_CNTR_CS_CONTENT_FROM_CONFIG_FILE):
        {
            return "Coordinate system cannot be changed because its content is loaded from a configuration file";
        }
        case(PI_CNTR_CS_CANNOT_BE_LINKED):
        {
            return "Coordinate system may not be linked";
        }
        case(PI_CNTR_KSB_CS_ROTATION_ONLY):
        {
            return "A KSB-type coordinate system can only be rotated by multiples of 90 degrees";
        }
        case(PI_CNTR_CS_DATA_CANNOT_BE_QUERIED):
        {
            return "This query is not supported for this coordinate system type";
        }
        case(PI_CNTR_CS_COMBINATION_DOES_NOT_EXIST):
        {
            return "This combination of work and tool coordinate systems does not exist";
        }
        case(PI_CNTR_CS_COMBINATION_INVALID):
        {
            return "The combination must consist of one work and one tool coordinate system";
        }
        case(PI_CNTR_CS_TYPE_DOES_NOT_EXIST):
        {
            return "This coordinate system type does not exist";
        }
        case(PI_CNTR_UNKNOWN_ERROR):
        {
            return "BasMac: unknown controller error";
        }
        case(PI_CNTR_CS_TYPE_NOT_ENABLED):
        {
            return "No coordinate system of this type is enabled";
        }
        case(PI_CNTR_CS_NAME_INVALID):
        {
            return "Name of coordinate system is invalid";
        }
        case(PI_CNTR_CS_GENERAL_FILE_MISSING):
        {
            return "File with stored CS systems is missing or erroneous";
        }
        case(PI_CNTR_CS_LEVELING_FILE_MISSING):
        {
            return "File with leveling CS is missing or erroneous";
        }
        case(PI_CNTR_NOT_ENOUGH_MEMORY):
        {
            return "Not enough memory";
        }
        case(PI_CNTR_HW_VOLTAGE_ERROR):
        {
            return "Hardware voltage error";
        }
        case(PI_CNTR_HW_TEMPERATURE_ERROR):
        {
            return "Hardware temperature out of range";
        }
        case(PI_CNTR_POSITION_ERROR_TOO_HIGH):
        {
            return "Position error of any axis in the system is too high";
        }
        case(PI_CNTR_INPUT_OUT_OF_RANGE):
        {
            return "Maximum value of input signal has been exceeded";
        }
        case(PI_CNTR_NO_INTEGER):
        {
            return "Value is not integer";
        }
        case(PI_CNTR_FAST_ALIGNMENT_PROCESS_IS_NOT_RUNNING):
        {
            return "Fast alignment process cannot be paused because it is not running";
        }
        case(PI_CNTR_FAST_ALIGNMENT_PROCESS_IS_NOT_PAUSED):
        {
            return "Fast alignment process cannot be restarted/resumed because it is not paused";
        }
        case(PI_CNTR_UNABLE_TO_SET_PARAM_WITH_SPA):
        {
            return "Parameter could not be set with SPA - SEP needed?";
        }
        case(PI_CNTR_PHASE_FINDING_ERROR):
        {
            return "Phase finding error";
        }
        case(PI_CNTR_SENSOR_SETUP_ERROR):
        {
            return "Sensor setup error";
        }
        case(PI_CNTR_SENSOR_COMM_ERROR):
        {
            return "Sensor communication error";
        }
        case(PI_CNTR_MOTOR_AMPLIFIER_ERROR):
        {
            return "Motor amplifier error";
        }
        case(PI_CNTR_OVER_CURR_PROTEC_TRIGGERED_BY_I2T):
        {
            return "Overcurrent protection triggered by I2T-module";
        }
        case(PI_CNTR_OVER_CURR_PROTEC_TRIGGERED_BY_AMP_MODULE):
        {
            return "Overcurrent protection triggered by amplifier module";
        }
        case(PI_CNTR_SAFETY_STOP_TRIGGERED):
        {
            return "Safety stop triggered";
        }
        case(PI_SENSOR_OFF):
        {
            return "Sensor off?";
        }
        case(PI_CNTR_PARAM_CONFLICT):
        {
            return "Parameter could not be set. Conflict with another parameter.";
        }
        case(PI_CNTR_COMMAND_NOT_ALLOWED_IN_EXTERNAL_MODE):
        {
            return "Command not allowed in external mode";
        }
        case(PI_CNTR_EXTERNAL_MODE_ERROR):
        {
            return "External mode communication error";
        }
        case(PI_CNTR_INVALID_MODE_OF_OPERATION):
        {
            return "Invalid mode of operation";
        }
        case(PI_CNTR_FIRMWARE_STOPPED_BY_CMD):
        {
            return "Firmware stopped by command (#27)";
        }
        case(PI_CNTR_EXTERNAL_MODE_DRIVER_MISSING):
        {
            return "External mode driver missing";
        }
        case(PI_CNTR_CONFIGURATION_FAILURE_EXTERNAL_MODE):
        {
            return "Missing or incorrect configuration of external mode";
        }
        case(PI_CNTR_EXTERNAL_MODE_CYCLETIME_INVALID):
        {
            return "External mode cycletime invalid";
        }
        case(PI_CNTR_BRAKE_ACTIVATED):
        {
            return "Brake is activated";
        }
        case(PI_CNTR_DRIVE_STATE_TRANSITION_ERROR):
        {
            return "Drive state transition error";
        }
        case(PI_CNTR_SURFACEDETECTION_RUNNING):
        {
            return "Command not allowed while surface detection is running";
        }
        case(PI_CNTR_SURFACEDETECTION_FAILED):
        {
            return "Last surface detection failed";
        }
        case(PI_CNTR_FIELDBUS_IS_ACTIVE):
        {
            return "Fieldbus is active and is blocking GCS control commands";
        }
        case(PI_CNTR_TOO_MANY_NESTED_MACROS):
        {
            return "Too many nested macros";
        }
        case(PI_CNTR_MACRO_ALREADY_DEFINED):
        {
            return "Macro already defined";
        }
        case(PI_CNTR_NO_MACRO_RECORDING):
        {
            return "Macro recording not activated";
        }
        case(PI_CNTR_INVALID_MAC_PARAM):
        {
            return "Invalid parameter for MAC";
        }
        case(PI_CNTR_MACRO_DELETE_ERROR):
        {
            return "Deleting macro failed";
        }
        case(PI_CNTR_CONTROLLER_BUSY):
        {
            return "Controller is busy with some lengthy operation (e.g. reference move, fast scan algorithm)";
        }
        case(PI_CNTR_INVALID_IDENTIFIER):
        {
            return "Invalid identifier (invalid special characters, ...)";
        }
        case(PI_CNTR_UNKNOWN_VARIABLE_OR_ARGUMENT):
        {
            return "Variable or argument not defined";
        }
        case(PI_CNTR_RUNNING_MACRO):
        {
            return "Controller is (already) running a macro";
        }
        case(PI_CNTR_MACRO_INVALID_OPERATOR):
        {
            return "Invalid or missing operator for condition. Check necessary spaces around operator.";
        }
        case(PI_CNTR_MACRO_NO_ANSWER):
        {
            return "No answer was received while executing WAC/MEX/JRC/...";
        }
        case(PI_CMD_NOT_VALID_IN_MACRO_MODE):
        {
            return "Command not valid during macro execution";
        }
        case(PI_CNTR_ERROR_IN_MACRO):
        {
            return "Error occured during macro execution";
        }
        case(PI_CNTR_NO_MACRO_OR_EMPTY):
        {
            return "No macro with given name on controller, or macro is empty";
        }
        case(PI_CNTR_INVALID_ARGUMENT):
        {
            return "One or more arguments given to function is invalid (empty string, index out of range, ...)";
        }
        case(PI_CNTR_MOTION_ERROR):
        {
            return "Motion error: position error too large, servo is switched off automatically";
        }
        case(PI_CNTR_MAX_MOTOR_OUTPUT_REACHED):
        {
            return "Maximum motor output reached";
        }
        case(PI_CNTR_UNKNOWN_CHANNEL_IDENTIFIER):
        {
            return "Unknown channel identifier";
        }
        case(PI_CNTR_EXT_PROFILE_UNALLOWED_CMD):
        {
            return "User Profile Mode: Command is not allowed, check for required preparatory commands";
        }
        case(PI_CNTR_EXT_PROFILE_EXPECTING_MOTION_ERROR):
        {
            return "User Profile Mode: First target position in User Profile is too far from current position";
        }
        case(PI_CNTR_PROFILE_ACTIVE):
        {
            return "Controller is (already) in User Profile Mode";
        }
        case(PI_CNTR_PROFILE_INDEX_OUT_OF_RANGE):
        {
            return "User Profile Mode: Block or Data Set index out of allowed range";
        }
        case(PI_CNTR_PROFILE_OUT_OF_MEMORY):
        {
            return "User Profile Mode: Out of memory";
        }
        case(PI_CNTR_PROFILE_WRONG_CLUSTER):
        {
            return "User Profile Mode: Cluster is not assigned to this axis";
        }
        case(PI_CNTR_PROFILE_UNKNOWN_CLUSTER_IDENTIFIER):
        {
            return "Unknown cluster identifier";
        }
        case(PI_CNTR_TOO_MANY_TCP_CONNECTIONS_OPEN):
        {
            return "There are too many open tcpip connections";
        }
        case(PI_CNTR_ALREADY_HAS_SERIAL_NUMBER):
        {
            return "Controller already has a serial number";
        }
        case(PI_CNTR_FEATURE_LICENSE_INVALID):
        {
            return "Entered license is invalid";
        }
        case(PI_CNTR_SECTOR_ERASE_FAILED):
        {
            return "Sector erase failed";
        }
        case(PI_CNTR_FLASH_PROGRAM_FAILED):
        {
            return "Flash program failed";
        }
        case(PI_CNTR_FLASH_READ_FAILED):
        {
            return "Flash read failed";
        }
        case(PI_CNTR_HW_MATCHCODE_ERROR):
        {
            return "HW match code missing/invalid";
        }
        case(PI_CNTR_FW_MATCHCODE_ERROR):
        {
            return "FW match code missing/invalid";
        }
        case(PI_CNTR_HW_VERSION_ERROR):
        {
            return "HW version missing/invalid";
        }
        case(PI_CNTR_FW_VERSION_ERROR):
        {
            return "FW version missing/invalid";
        }
        case(PI_CNTR_FW_UPDATE_ERROR):
        {
            return "FW update failed";
        }
        case(PI_CNTR_FW_CRC_PAR_ERROR):
        {
            return "FW Parameter CRC wrong";
        }
        case(PI_CNTR_FW_CRC_FW_ERROR):
        {
            return "FW CRC wrong";
        }
        case(PI_CNTR_INVALID_PCC_SCAN_DATA):
        {
            return "PicoCompensation scan data is not valid";
        }
        case(PI_CNTR_PCC_SCAN_RUNNING):
        {
            return "PicoCompensation is running, some actions can not be executed during scanning/recording";
        }
        case(PI_CNTR_INVALID_PCC_AXIS):
        {
            return "Given axis can not be defined as PPC axis";
        }
        case(PI_CNTR_PCC_SCAN_OUT_OF_RANGE):
        {
            return "Defined scan area is larger than the travel range";
        }
        case(PI_CNTR_PCC_TYPE_NOT_EXISTING):
        {
            return "Given PicoCompensation type is not defined";
        }
        case(PI_CNTR_PCC_PAM_ERROR):
        {
            return "PicoCompensation parameter error";
        }
        case(PI_CNTR_PCC_TABLE_ARRAY_TOO_LARGE):
        {
            return "PicoCompensation table is larger than maximum table length";
        }
        case(PI_CNTR_NEXLINE_ERROR):
        {
            return "Common error in Nexline firmware module";
        }
        case(PI_CNTR_CHANNEL_ALREADY_USED):
        {
            return "Output channel for Nexline can not be redefined for other usage";
        }
        case(PI_CNTR_NEXLINE_TABLE_TOO_SMALL):
        {
            return "Memory for Nexline signals is too small";
        }
        case(PI_CNTR_RNP_WITH_SERVO_ON):
        {
            return "RNP can not be executed if axis is in closed loop";
        }
        case(PI_CNTR_RNP_NEEDED):
        {
            return "relax procedure (RNP) needed";
        }
        case(PI_CNTR_AXIS_NOT_CONFIGURED):
        {
            return "Axis must be configured for this action";
        }
        case(PI_CNTR_FREQU_ANALYSIS_FAILED):
        {
            return "Frequency analysis failed";
        }
        case(PI_CNTR_FREQU_ANALYSIS_RUNNING):
        {
            return "Another frequency analysis is running";
        }
        case(PI_CNTR_SENSOR_ABS_INVALID_VALUE):
        {
            return "Invalid preset value of absolute sensor";
        }
        case(PI_CNTR_SENSOR_ABS_WRITE_ERROR):
        {
            return "Error while writing to sensor";
        }
        case(PI_CNTR_SENSOR_ABS_READ_ERROR):
        {
            return "Error while reading from sensor";
        }
        case(PI_CNTR_SENSOR_ABS_CRC_ERROR):
        {
            return "Checksum error of absolute sensor";
        }
        case(PI_CNTR_SENSOR_ABS_ERROR):
        {
            return "General error of absolute sensor";
        }
        case(PI_CNTR_SENSOR_ABS_OVERFLOW):
        {
            return "Overflow of absolute sensor position";
        }

///////////////////////////////////////////////////////////////////////////////
//
// UMF Errors
//
///////////////////////////////////////////////////////////////////////////////

        case(PI_ERROR_CMD_NUMBER_OF_ARGUMENTS):
        {
            return "Wrong number of arguments";
        }
        case(PI_ERROR_CMD_UNKNOWN_COMMAND):
        {
            return "Unknown command";
        }
        case(PI_ERROR_CMD_COMMAND_LEVEL_TOO_LOW_FOR_COMMAND_ACCESS):
        {
            return "User command level too low for command access";
        }
        case(PI_ERROR_CMD_INVALID_PWD):
        {
            return "Invalid password";
        }
        case(PI_ERROR_PARAM_WRONG_DATA_TYPE):
        {
            return "Wrong data type";
        }
        case(PI_ERROR_PARAM_UNKNOWN_PARAMETER_ID):
        {
            return "Unknown parameter ID";
        }
        case(PI_ERROR_PARAM_COMMAND_LEVEL_TOO_LOW_FOR_PARAMETER_ACCESS):
        {
            return "User command level too low for parameter access";
        }
        case(PI_ERROR_PARAM_INVALID_VALUE):
        {
            return "Argument value not valid";
        }
        case(PI_ERROR_PARAM_WRONG_PARAMETER_TYPE):
        {
            return "Wrong parameter type";
        }
        case(PI_ERROR_PARAM_VALUE_OUT_OF_RANGE):
        {
            return "Argument value out of range";
        }
        case(PI_ERROR_MOTION_ON_LIMIT_SWITCH):
        {
            return "Motion not possible due to active limit switch";
        }
        case(PI_ERROR_MOTION_INVALID_MODE_OF_OPERATION):
        {
            return "Invalid mode of operation";
        }
        case(PI_ERROR_MOTION_MOVE_WITHOUT_REF):
        {
            return "Axis not referenced";
        }
        case(PI_ERROR_MOTION_TARGET_OUT_OF_RANGE):
        {
            return "Target out of range";
        }
        case(PI_ERROR_MOTION_AXIS_DISABLED):
        {
            return "Axis is disabled";
        }
        case(PI_ERROR_MOTION_LIMIT_SWITCH_ACTIVATED):
        {
            return "Axis has activated a limit switch";
        }
        case(PI_ERROR_MOTION_OVER_CURRENT_PROTECTION):
        {
            return "Motor current is too high, servo is switched off automatically";
        }
        case(PI_ERROR_MOTION_POSITION_ERROR_TOO_LARGE):
        {
            return "Position error too large, servo is switched off automatically";
        }
        case(PI_ERROR_RECORDER_MAX_DATA_RECORDER_NUMBER_REACHED):
        {
            return "The max number of storable data recorders has been reached";
        }
        case(PI_ERROR_RECORDER_ALREADY_REGISTERED):
        {
            return "The given data recorder has already been registered";
        }
        case(PI_ERROR_RECORDER_NOT_IN_CONFIG_MODE):
        {
            return "Data recorder is not in configuration mode";
        }
        case(PI_ERROR_RECORDER_ALREADY_RUNNING):
        {
            return "Data recorder is already running";
        }
        case(PI_ERROR_RECORDER_TRACE_DOES_NOT_EXIST):
        {
            return "Specified data recorder trace does not exist";
        }
        case(PI_ERROR_RECORDER_NOT_ENOUGH_RECORDED_DATA):
        {
            return "Not enough recorded data in at least one data recorder trace";
        }
        case(PI_ERROR_RECORDER_TRACES_NOT_CONFIGURED):
        {
            return "Data recorder traces are not configured";
        }
        case(PI_ERROR_COM_COMMUNICATION_ERROR):
        {
            return "Controller detected communication error";
        }
        case(PI_ERROR_COM_FW_INDEX_UNKNOWN):
        {
            return "Firmware index unknown";
        }
        case(PI_ERROR_COM_TIMEOUT):
        {
            return "Timeout occurred";
        }
        case(PI_ERROR_COM_INVALID_SOCKET):
        {
            return "Invalid Socket";
        }
        case(PI_ERROR_SYS_UNIT_NOT_INITIALIZED):
        {
            return "Unit not initialized";
        }
        case(PI_ERROR_SYS_MAX_CONNECTION_NUMBER_REACHED):
        {
            return "The max number of storable connections has been reached";
        }
        case(PI_ERROR_SYS_CONNECTION_OUTPUT_WRONG_ARGUMENTS):
        {
            return "Wrong arguments when setting a connection output";
        }
        case(PI_ERROR_SYS_CONNECTION_INPUT_WRONG_ARGUMENTS):
        {
            return "Wrong arguments when setting a connection input";
        }
        case(PI_ERROR_SYS_WRONG_UNIT_ID_FORMAT):
        {
            return "Wrong unit ID format given";
        }
        case(PI_ERROR_SYS_WRONG_DEVICE_ID):
        {
            return "Wrong device ID";
        }
        case(PI_ERROR_SYS_WRONG_FUNCTION_ID):
        {
            return "Wrong function ID";
        }
        case(PI_ERROR_SYS_WRONG_PROXY_ID):
        {
            return "Wrong proxy ID";
        }
        case(PI_ERROR_SYS_CONNECTION_OUTPUT_INDEX_OUT_OF_RANGE):
        {
            return "Connection output index is out of range";
        }
        case(PI_ERROR_SYS_INTERFACE_REGISTRATION_FAILED):
        {
            return "Failed to register an interface in the bus gateway";
        }
        case(PI_ERROR_SYS_DEVICE_REGISTRATION_FAILED):
        {
            return "Failed to register a device in the bus gateway";
        }
        case(PI_ERROR_SYS_PROXY_REGISTRATION_FAILED):
        {
            return "Failed to register a proxy in the bus gateway";
        }
        case(PI_ERROR_SYS_INPUT_PORT_ALREADY_CONNECTED):
        {
            return "The given input port has already been registered in another connection";
        }
        case(PI_ERROR_SYS_UNIT_ALREADY_REGISTERED):
        {
            return "The given unit has already been registered to the broker";
        }
        case(PI_ERROR_SYS_CONNECTION_HAS_NO_INPUT):
        {
            return "The connection has no input";
        }
        case(PI_ERROR_SYS_CONNECTION_HAS_NO_OUTPUT):
        {
            return "The connection has no output";
        }
        case(PI_ERROR_SYS_CONNECTION_NOT_FOUND):
        {
            return "The sought connection is not registered";
        }
        case(PI_ERROR_SYS_INPUT_PORT_NOT_CONNECTED):
        {
            return "The input port is not connected";
        }
        case(PI_ERROR_SYS_DATA_CORRUPT):
        {
            return "Data corrupted";
        }
        case(PI_ERROR_SYS_FW_UPDATE_ERROR):
        {
            return "Firmware update failed";
        }
        case(PI_ERROR_SYS_UNIT_NOT_FOUND):
        {
            return "Unit could not be found";
        }
        case(PI_ERROR_SYS_UNIT_TYPE_NOT_SUPPORTED):
        {
            return "Unit type not supported";
        }
        case(PI_ERROR_SYS_NOT_ENOUGH_MEMORY):
        {
            return "Not enough memory";
        }
        case(PI_ERROR_SYS_NO_DATA_AVAILABLE):
        {
            return "No data available";
        }
        case(PI_ERROR_SYS_FLASH_READ_FAILED):
        {
            return "Flash read failed";
        }
        case(PI_ERROR_SYS_FATAL_ERROR):
        {
            return "Fatal system error occurred";
        }
        default:
        {
            std::stringstream errorMessage;
            errorMessage << "Unknown Error - number " << error;
            return errorMessage.str();
        }
    }
}

bool TranslatePIError(epicsInt32 error, char* szBuffer, epicsUInt32 maxlen)
{
    std::string errmsg = TranslatePIError(error);
    if (errmsg.size() < maxlen)
    {
        strcpy(szBuffer, errmsg.c_str());
        return true;
    }
    return false;
}
