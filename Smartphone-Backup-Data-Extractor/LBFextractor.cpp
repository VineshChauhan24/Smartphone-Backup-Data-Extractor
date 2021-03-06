#include "LBF.h"
#include "myFile.h"


//########################################### LG Patterns ###########################################//

// ALARMS
char LG_ALARMS_START[44] = {0x2F, 0x64, 0x61, 0x74, 0x61, 0x2F, 0x64, 0x61, 0x74, 0x61, 0x2F, 0x63, 0x6F, 0x6D, 0x2E, 0x6C, 0x67, 0x65, 0x2E, 0x63,
						    0x6C, 0x6F, 0x63, 0x6B, 0x2F, 0x64, 0x61, 0x74, 0x61, 0x62, 0x61, 0x73, 0x65, 0x73, 0x2F, 0x61, 0x6C, 0x61, 0x72, 0x6D,
						    0x73, 0x2E, 0x64, 0x62 }; // /data/data/com.lge.clock/databases/alarms.db

char LG_ALARMS_END[9]	= {0x63, 0x6F, 0x75, 0x6E, 0x74, 0x20, 0x3D, 0x20, 0x31};		// count = 1
char* LG_ALARMS_FILENAME = "alarms";

// Contacts
char LG_CONTACTS_START[66] = {0x2F, 0x64, 0x61, 0x74, 0x61, 0x2F, 0x75, 0x73, 0x65, 0x72, 0x2F, 0x30, 0x2F, 0x63, 0x6F, 0x6D, 0x2E, 0x61, 0x6E, 0x64, 
							  0x72, 0x6F, 0x69, 0x64, 0x2E, 0x70, 0x72, 0x6F, 0x76, 0x69, 0x64, 0x65, 0x72, 0x73, 0x2E, 0x63, 0x6F, 0x6E, 0x74, 0x61,
							  0x63, 0x74, 0x73, 0x2F, 0x64, 0x61, 0x74, 0x61, 0x62, 0x61, 0x73, 0x65, 0x73, 0x2F, 0x63, 0x6F, 0x6E, 0x74, 0x61, 0x63,
							  0x74, 0x73, 0x32, 0x2E, 0x64, 0x62};	// /data/user/0/com.android.providers.contacts/databases/contacts2.db
char LG_CONTACTS_END[25]   = {0x63, 0x6F, 0x6E, 0x74, 0x61, 0x63, 0x74, 0x73, 0x32, 0x2E, 0x64, 0x62, 0x66, 0x69, 0x6C, 0x65, 0x20, 0x63, 0x6F, 0x75,
							  0x6E, 0x74, 0x20, 0x3D, 0x20}; // contacts2.dbfile count = 
char* LG_CONTACTS_FILENAME = "contacts";

// SMS
char LG_SMS_START[13] = {0x2F, 0x53, 0x6D, 0x73, 0x2F, 0x73, 0x6D, 0x73, 0x2E, 0x76, 0x6D, 0x73, 0x67}; // /Sms/sms.vmsg
char LG_SMS_END[32]   = {0x2F, 0x4D, 0x6D, 0x73, 0x2F, 0x6D, 0x6D, 0x73, 0x5F, 0x62, 0x61, 0x63, 0x6B, 0x75, 0x70, 0x2E, 0x78, 0x6D, 0x6C, 0x66,
						 0x69, 0x6C, 0x65, 0x20, 0x63, 0x6F, 0x75, 0x6E, 0x74, 0x20, 0x3D, 0x20}; // /Mms/mms_backup.xmlfile count = 
char* LG_SMS_FILENAME = "sms";

// Browser
char LG_BROWSER_START[52] = {0x2F, 0x64, 0x61, 0x74, 0x61, 0x2F, 0x64, 0x61, 0x74, 0x61, 0x2F, 0x63, 0x6F, 0x6D, 0x2E, 0x61, 0x6E, 0x64, 0x72, 0x6F,
							 0x69, 0x64, 0x2E, 0x62, 0x72, 0x6F, 0x77, 0x73, 0x65, 0x72, 0x2F, 0x64, 0x61, 0x74, 0x61, 0x62, 0x61, 0x73, 0x65, 0x73,
							 0x2F, 0x62, 0x72, 0x6F, 0x77, 0x73, 0x65, 0x72, 0x32, 0x2E, 0x64, 0x62}; // /data/data/com.android.browser/databases/browser2.db
char LG_BROWSER_END[17]   = {0x77, 0x61, 0x6C, 0x66, 0x69, 0x6C, 0x65, 0x20, 0x63, 0x6F, 0x75, 0x6E, 0x74, 0x20, 0x3D, 0x20, 0x33};	//walfile count = 3
char* LG_BROWSER_FILENAME = "browser";

// VoiceRecord - 테스트 필요(뒤에 Tasks가 항상 바로 오는지 확인)
char LG_VOICERECORD_START[35] = {0x2F, 0x69, 0x6E, 0x74, 0x65, 0x72, 0x6E, 0x61, 0x6C, 0x40, 0x2F, 0x56, 0x6F, 0x69, 0x63, 0x65, 0x52, 0x65, 0x63, 0x6F,
								 0x72, 0x64, 0x65, 0x72, 0x2F, 0x6D, 0x79, 0x5F, 0x73, 0x6F, 0x75, 0x6E, 0x64, 0x73, 0x2F}; // /internal@/VoiceRecorder/my_sounds/
char LG_VOICERECORD_END[42]   = {0x2F, 0x64, 0x61, 0x74, 0x61, 0x2F, 0x64, 0x61, 0x74, 0x61, 0x2F, 0x63, 0x6F, 0x6D, 0x2E, 0x6C, 0x67, 0x65, 0x2E, 0x74,
						         0x61, 0x73, 0x6B, 0x2F, 0x64, 0x61, 0x74, 0x61, 0x62, 0x61, 0x73, 0x65, 0x73, 0x2F, 0x74, 0x61, 0x73, 0x6B, 0x73, 0x2E,
						         0x64, 0x62}; // /data/data/com.lge.task/databases/tasks.db
char* LG_VOICERECORD_FILENAME = "VoiceRecorder";

// Tasks
char LG_TASKS_START[42] = {0x2F, 0x64, 0x61, 0x74, 0x61, 0x2F, 0x64, 0x61, 0x74, 0x61, 0x2F, 0x63, 0x6F, 0x6D, 0x2E, 0x6C, 0x67, 0x65, 0x2E, 0x74,
						  0x61, 0x73, 0x6B, 0x2F, 0x64, 0x61, 0x74, 0x61, 0x62, 0x61, 0x73, 0x65, 0x73, 0x2F, 0x74, 0x61, 0x73, 0x6B, 0x73, 0x2E,
						  0x64, 0x62};	// /data/data/com.lge.task/databases/tasks.db
char LG_TASKS_END[9]	= {0x63, 0x6F, 0x75, 0x6E, 0x74, 0x20, 0x3D, 0x20, 0x31}; // count = 1
char* LG_TASKS_FILENAME = "tasks";

//QMemoPlus
char LG_QMEMOPLUS_START[51] = {0x2F, 0x64, 0x61, 0x74, 0x61, 0x2F, 0x64, 0x61, 0x74, 0x61, 0x2F, 0x63, 0x6F, 0x6D, 0x2E, 0x6C, 0x67, 0x65, 0x2E, 0x71,
							   0x6D, 0x65, 0x6D, 0x6F, 0x70, 0x6C, 0x75, 0x73, 0x2F, 0x64, 0x61, 0x74, 0x61, 0x62, 0x61, 0x73, 0x65, 0x73, 0x2F, 0x71,
							   0x6D, 0x65, 0x6D, 0x6F, 0x70, 0x6C, 0x75, 0x73, 0x2E, 0x64, 0x62}; // /data/data/com.lge.qmemoplus/databases/qmemoplus.db
char LG_QMEMOPLUS_END[26]	= {0x71, 0x6D, 0x65, 0x6D, 0x6F, 0x70, 0x6C, 0x75, 0x73, 0x2E, 0x64, 0x62, 0x66, 0x69, 0x6C, 0x65, 0x20, 0x63, 0x6F, 0x75,
							   0x6E, 0x74, 0x20, 0x3D, 0x20, 0x31}; // qmemoplus.dbfile count = 1
char* LG_QMEMOPLUS_FILENAME = "Qmemo+";

//Qremote
char LG_QREMOTE_START[55] = {0x2F, 0x64, 0x61, 0x74, 0x61, 0x2F, 0x64, 0x61, 0x74, 0x61, 0x2F, 0x63, 0x6F, 0x6D, 0x2E, 0x6C, 0x67, 0x65, 0x2E, 0x71,
							 0x72, 0x65, 0x6D, 0x6F, 0x74, 0x65, 0x2F, 0x64, 0x61, 0x74, 0x61, 0x62, 0x61, 0x73, 0x65, 0x73, 0x2F, 0x71, 0x72, 0x65,
							 0x6D, 0x6F, 0x74, 0x65, 0x73, 0x65, 0x74, 0x74, 0x69, 0x6E, 0x67, 0x73, 0x2E, 0x64, 0x62};	// /data/data/com.lge.qremote/databases/qremotesettings.db
char LG_QREMOTE_END[21]	  = {0x6A, 0x6F, 0x75, 0x72, 0x6E, 0x61, 0x6C, 0x66, 0x69, 0x6C, 0x65, 0x20, 0x63, 0x6F, 0x75, 0x6E, 0x74, 0x20, 0x3D, 0x20,
							 0x32};	// journalfile count = 2
char* LG_QREMOTE_FILENAME = "Qremote";

// Forecast
char LG_FORECAST_START[64] = {0x2F, 0x64, 0x61, 0x74, 0x61, 0x2F, 0x64, 0x61, 0x74, 0x61, 0x2F, 0x63, 0x6F, 0x6D, 0x2E, 0x6C, 0x67, 0x65, 0x2E, 0x73,
							  0x69, 0x7A, 0x65, 0x63, 0x68, 0x61, 0x6E, 0x67, 0x61, 0x62, 0x6C, 0x65, 0x2E, 0x77, 0x65, 0x61, 0x74, 0x68, 0x65, 0x72,
							  0x2F, 0x64, 0x61, 0x74, 0x61, 0x62, 0x61, 0x73, 0x65, 0x73, 0x2F, 0x66, 0x6F, 0x72, 0x65, 0x63, 0x61, 0x73, 0x74, 0x5F,
							  0x6B, 0x2E, 0x64, 0x62};  // /data/data/com.lge.sizechangable.weather/databases/forecast_k.db
char LG_FORECAST_END[50]   = {0x2F, 0x63, 0x6F, 0x6D, 0x2E, 0x6C, 0x67, 0x65, 0x2E, 0x73, 0x69, 0x7A, 0x65, 0x63, 0x68, 0x61, 0x6E, 0x67, 0x61, 0x62,
							  0x6C, 0x65, 0x2E, 0x77, 0x65, 0x61, 0x74, 0x68, 0x65, 0x72, 0x5F, 0x70, 0x72, 0x65, 0x66, 0x65, 0x72, 0x65, 0x6E, 0x63,
							  0x65, 0x73, 0x2E, 0x78, 0x6D, 0x6C, 0x66, 0x69, 0x6C, 0x65};	// /com.lge.sizechangable.weather_preferences.xmlfile
char* LG_FORECAST_FILENAME = "forecast";

// Settings
char LG_SETTINGS_START[63] = {0x2F, 0x64, 0x61, 0x74, 0x61, 0x2F, 0x64, 0x61, 0x74, 0x61, 0x2F, 0x63, 0x6F, 0x6D, 0x2E, 0x61, 0x6E, 0x64, 0x72, 0x6F,
						      0x69, 0x64, 0x2E, 0x70, 0x72, 0x6F, 0x76, 0x69, 0x64, 0x65, 0x72, 0x73, 0x2E, 0x73, 0x65, 0x74, 0x74, 0x69, 0x6E, 0x67,
							  0x73, 0x2F, 0x64, 0x61, 0x74, 0x61, 0x62, 0x61, 0x73, 0x65, 0x73, 0x2F, 0x73, 0x65, 0x74, 0x74, 0x69, 0x6E, 0x67, 0x73,
							  0x2E, 0x64, 0x62};  // /data/data/com.android.providers.settings/databases/settings.db
char LG_SETTINGS_END[18]   = {0x63, 0x6F, 0x6E, 0x66, 0x66, 0x69, 0x6C, 0x65, 0x20, 0x63, 0x6F, 0x75, 0x6E, 0x74, 0x20, 0x3D, 0x20, 0x32};	// conffile count = 2
char* LG_SETTINGS_FILENAME = "settings";

// Lock Settings
char LG_LOCK_START[63] = {0x2F, 0x64, 0x61, 0x74, 0x61, 0x2F, 0x64, 0x61, 0x74, 0x61, 0x2F, 0x63, 0x6F, 0x6D, 0x2E, 0x6C, 0x67, 0x65, 0x2E, 0x6C,
						  0x6F, 0x63, 0x6B, 0x73, 0x63, 0x72, 0x65, 0x65, 0x6E, 0x73, 0x65, 0x74, 0x74, 0x69, 0x6E, 0x67, 0x73, 0x2F, 0x64, 0x61,
						  0x74, 0x61, 0x62, 0x61, 0x73, 0x65, 0x73, 0x2F, 0x6C, 0x6F, 0x63, 0x6B, 0x73, 0x65, 0x74, 0x74, 0x69, 0x6E, 0x67, 0x73,
						  0x2E, 0x64, 0x62}; // /data/data/com.lge.lockscreensettings/databases/locksettings.db
char LG_LOCK_END[40]   = {0x77, 0x61, 0x6C, 0x6C, 0x70, 0x61, 0x70, 0x65, 0x72, 0x5F, 0x69, 0x6E, 0x64, 0x65, 0x78, 0x5F, 0x62, 0x61, 0x63, 0x6B,
	                      0x75, 0x70, 0x2E, 0x74, 0x78, 0x74, 0x66, 0x69, 0x6C, 0x65, 0x20, 0x63, 0x6F, 0x75, 0x6E, 0x74, 0x20, 0x3D, 0x20, 0x33}; // wallpaper_index_backup.txtfile count = 3
char* LG_LOCK_FILENAME = "Lock_settings";

// Life Tracker
char LG_LIFETRACKER_START[56] = {0x2F, 0x64, 0x61, 0x74, 0x61, 0x2F, 0x64, 0x61, 0x74, 0x61, 0x2F, 0x63, 0x6F, 0x6D, 0x2E, 0x6C, 0x67, 0x65, 0x2E, 0x6C,
								 0x69, 0x66, 0x65, 0x74, 0x72, 0x61, 0x63, 0x6B, 0x65, 0x72, 0x2F, 0x64, 0x61, 0x74, 0x61, 0x62, 0x61, 0x73, 0x65, 0x73,
								 0x2F, 0x6C, 0x69, 0x66, 0x65, 0x74, 0x72, 0x61, 0x63, 0x6B, 0x65, 0x72, 0x32, 0x2E, 0x64, 0x62}; // /data/data/com.lge.lifetracker/databases/lifetracker2.db
char LG_LIFETRACKER_END[29]   = {0x6C, 0x69, 0x66, 0x65, 0x74, 0x72, 0x61, 0x63, 0x6B, 0x65, 0x72, 0x32, 0x2E, 0x64, 0x62, 0x66, 0x69, 0x6C, 0x65, 0x20,
								 0x63, 0x6F, 0x75, 0x6E, 0x74, 0x20, 0x3D, 0x20, 0x31}; // lifetracker2.dbfile count = 1
char* LG_LIFETRACKER_FILENAME = "lifetracker";

// Call Settings
char LG_CALLSETTINGS_START[52] = {0x2F, 0x64, 0x61, 0x74, 0x61, 0x2F, 0x64, 0x61, 0x74, 0x61, 0x2F, 0x63, 0x6F, 0x6D, 0x2E, 0x61, 0x6E, 0x64, 0x72, 0x6F,
								  0x69, 0x64, 0x2E, 0x70, 0x68, 0x6F, 0x6E, 0x65, 0x2F, 0x64, 0x61, 0x74, 0x61, 0x62, 0x61, 0x73, 0x65, 0x73, 0x2F, 0x63,
								  0x61, 0x6C, 0x6C, 0x72, 0x65, 0x6A, 0x65, 0x63, 0x74, 0x2E, 0x64, 0x62}; // /data/data/com.android.phone/databases/callreject.db
char LG_CALLSETTINGS_END[18]   = {0x78, 0x6D, 0x6C, 0x66, 0x69, 0x6C, 0x65, 0x20, 0x63, 0x6F, 0x75, 0x6E, 0x74, 0x20, 0x3D, 0x20, 0x31, 0x30}; // xmlfile count = 10
char* LG_CALLSETTINGS_FILENAME = "Call_settings";

// MENU For Backup
char LG_BMENU_START[45] = {0x2F, 0x73, 0x74, 0x6F, 0x72, 0x61, 0x67, 0x65, 0x2F, 0x65, 0x6D, 0x75, 0x6C, 0x61, 0x74, 0x65, 0x64, 0x2F, 0x30, 0x2F,
						  0x48, 0x6F, 0x6D, 0x65, 0x2F, 0x6D, 0x65, 0x6E, 0x75, 0x5F, 0x66, 0x6F, 0x72, 0x5F, 0x6C, 0x67, 0x62, 0x61, 0x63, 0x6B,
						  0x75, 0x70, 0x2E, 0x64, 0x62}; // /storage/emulated/0/Home/menu_for_lgbackup.db
char LG_BMENU_END[40]   = {0x2F, 0x77, 0x6F, 0x72, 0x6B, 0x73, 0x70, 0x61, 0x63, 0x65, 0x5F, 0x66, 0x6F, 0x72, 0x5F, 0x6C, 0x67, 0x62, 0x61, 0x63,
						  0x6B, 0x75, 0x70, 0x2E, 0x64, 0x62, 0x66, 0x69, 0x6C, 0x65, 0x20, 0x63, 0x6F, 0x75, 0x6E, 0x74, 0x20, 0x3D, 0x20, 0x33}; // /workspace_for_lgbackup.dbfile count = 3
char* LG_BMENU_FILENAME = "menu_for_backup";

///////////////////////////////////////////////  Functions  ///////////////////////////////////////////////

LBF::LBF()
{
} // Constructor

LBF::~LBF()
{
} // Destructor

int LBF::Extract(char* inPath, char* outPath, char* pattern1, int size1, char* pattern2, int size2, char* name, char* extension, int wild1, int wild2, int only)
{
	int length=0, fileCount=0;
	long offset=0;
	int start=-1, end=-1;
	int onlyone = 0;

	FILE* bfile;
	MyFile mylbf;

	// 백업파일 열기
	fopen_s(&bfile, inPath, "rb");
	if( bfile == NULL ) {
		puts("ReadFile open Error");
		return 0;
	}
	
	//버퍼 초기화
	char buffer[4096];
	memset(buffer, NULL, sizeof(buffer));

	while(1) {
		offset = ftell(bfile);

		// 버퍼 길이 체크
		length = fread(buffer, 1, sizeof(buffer), bfile);

		if(length < size1) {
			//cout << " [ Nothing to extract more ]" << endl;
			break;
		}

		// Signature 검색 (KMP알고리즘 활용)
		start = mylbf.KMP(buffer, length, pattern1, size1);

		if(start != -1)
		{
			//cout << " [ Start Signature is found! ]" << endl;
			start += offset;
			fileCount++;
			while(1)
			{
				end = mylbf.KMP(buffer, length, pattern2, size2);

				if(end == -1) {
					fseek(bfile, 1-size2, SEEK_CUR);
					offset = ftell(bfile);

					// 버퍼 길이 체크
					length = fread(buffer, 1, sizeof(buffer), bfile);

					if( length < size2 ) {
						//cout << " [ There is only start signature ]" << endl;
						fileCount--;
						break;
					}
				}

				else if(end != -1) {
					//cout << " [ End Signature is found! ]" << endl;
					end += offset;
					mylbf.WriteFile(wild1, start, end+size2, wild2, inPath, outPath, name, fileCount, extension);
					fseek(bfile, end+size1+size2+wild2-1, SEEK_SET);
					if(only == 1) onlyone = 1;
					break;			
				}
			} // End of while_END signature
		}
		start = offset + 1;
		fseek(bfile, 1-size1, SEEK_CUR);
		if(onlyone == 1) break;
	} // End of while_Start signature

	fclose(bfile);

	return fileCount;
}

int LBF::LBF_Extractor(char* inputPath, char* outputPath)
{
	int nfile=0;
	
	// 알람
	nfile += LBF::Extract(inputPath, outputPath, LG_ALARMS_START, sizeof(LG_ALARMS_START), LG_ALARMS_END, sizeof(LG_ALARMS_END), LG_ALARMS_FILENAME, PK_EXTENSION, 30, 22, 1);

	// 전화번호부
	nfile += LBF::Extract(inputPath, outputPath, LG_CONTACTS_START, sizeof(LG_CONTACTS_START), LG_CONTACTS_END, sizeof(LG_CONTACTS_END), LG_CONTACTS_FILENAME, PK_EXTENSION, 30, 23, 0);

	// 문자메시지
	nfile += LBF::Extract(inputPath, outputPath, LG_SMS_START, sizeof(LG_SMS_START), LG_SMS_END, sizeof(LG_SMS_END), LG_SMS_FILENAME, PK_EXTENSION, 30, 23, 0);

	// 브라우저
	nfile += LBF::Extract(inputPath, outputPath, LG_BROWSER_START, sizeof(LG_BROWSER_START), LG_BROWSER_END, sizeof(LG_BROWSER_END), LG_BROWSER_FILENAME, PK_EXTENSION, 30, 22, 1);

	// 음성녹음
	nfile += LBF::Extract(inputPath, outputPath, LG_VOICERECORD_START, sizeof(LG_VOICERECORD_START), LG_VOICERECORD_END, sizeof(LG_VOICERECORD_END), LG_VOICERECORD_FILENAME, PK_EXTENSION, 30, -72, 1);

	// 할일
	nfile += LBF::Extract(inputPath, outputPath, LG_TASKS_START, sizeof(LG_TASKS_START), LG_TASKS_END, sizeof(LG_TASKS_END), LG_TASKS_FILENAME, PK_EXTENSION, 30, 22, 1);

	// Q메모
	nfile += LBF::Extract(inputPath, outputPath, LG_QMEMOPLUS_START, sizeof(LG_QMEMOPLUS_START), LG_QMEMOPLUS_END, sizeof(LG_QMEMOPLUS_END), LG_QMEMOPLUS_FILENAME, PK_EXTENSION, 30, 22, 1);

	// Q리모트
	nfile += LBF::Extract(inputPath, outputPath, LG_QREMOTE_START, sizeof(LG_QREMOTE_START), LG_QREMOTE_END, sizeof(LG_QREMOTE_END), LG_QREMOTE_FILENAME, PK_EXTENSION, 30, 22, 1);

	// 날씨
	nfile += LBF::Extract(inputPath, outputPath, LG_FORECAST_START, sizeof(LG_FORECAST_START), LG_FORECAST_END, sizeof(LG_FORECAST_END), LG_FORECAST_FILENAME, PK_EXTENSION, 30, 32, 1);

	// 환경 설정
	nfile += LBF::Extract(inputPath, outputPath, LG_SETTINGS_START, sizeof(LG_SETTINGS_START), LG_SETTINGS_END, sizeof(LG_SETTINGS_END), LG_SETTINGS_FILENAME, PK_EXTENSION, 30, 22, 1);

	// 잠금화면 설정
	nfile += LBF::Extract(inputPath, outputPath, LG_LOCK_START, sizeof(LG_LOCK_START), LG_LOCK_END, sizeof(LG_LOCK_END), LG_LOCK_FILENAME, PK_EXTENSION, 30, 22, 1);

	// 라이프
	nfile += LBF::Extract(inputPath, outputPath, LG_LIFETRACKER_START, sizeof(LG_LIFETRACKER_START), LG_LIFETRACKER_END, sizeof(LG_LIFETRACKER_END), LG_LIFETRACKER_FILENAME, PK_EXTENSION, 30, 22, 1);

	// 통화 설정
	nfile += LBF::Extract(inputPath, outputPath, LG_CALLSETTINGS_START, sizeof(LG_CALLSETTINGS_START), LG_CALLSETTINGS_END, sizeof(LG_CALLSETTINGS_END), LG_CALLSETTINGS_FILENAME, PK_EXTENSION, 30, 22, 1);

	// 백업 메뉴
	nfile += LBF::Extract(inputPath, outputPath, LG_BMENU_START, sizeof(LG_BMENU_START), LG_BMENU_END, sizeof(LG_BMENU_END), LG_BMENU_FILENAME, PK_EXTENSION, 30, 22, 1);

	return nfile;
}

