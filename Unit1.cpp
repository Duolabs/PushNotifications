//===========================================================================
//===========================================================================
// Application Name: FirebaseCloudMessaging
//
// By Duolabs Srl
// Web: www.duolabs.com
//
// Author Riccardo Alessi
// Creation Date Aug 14th 2018
//
// All Rights Reserved
//===========================================================================
//===========================================================================
//
// ==========================================================================
// Version 0.0.6
// Dated: Aug 17th 2018
//
// --------------------------------------------------------------------------
//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Unit1.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory>

#include <system.SysUtils.hpp>
#include <system.Types.hpp>
#include <system.UITypes.hpp>
#include <system.Classes.hpp>
#include <system.Variants.hpp>

// Global Push Notifications File
#include <system.pushnotification.hpp>

// Delphi World Push Client
#include <DW.PushClient.hpp>

#include <FMX.Types.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Graphics.hpp>
#include <FMX.Dialogs.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.ScrollBox.hpp>
#include <FMX.Memo.hpp>


#include <system.net.httpclient.hpp>
#include <system.threading.hpp>


//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}

bool __fastcall CheckInet()
{
	bool result = false;
	THTTPClient *aHTTP = THTTPClient::Create();
	try {
		try {
			_di_IHTTPResponse aResp = aHTTP->Head("http://google.com");
			result = (aResp->StatusCode < 400);
		}
		catch (const System::Sysutils::Exception &E) {
			result = false;
		}
	}
 __finally {
	delete aHTTP;
 }

 return result;
}

//---------------------------------------------------------------------------
void __fastcall TForm1::ResendRequestButClick(TObject *Sender)
{
	// Token Request here.

	FPushClient = new TPushClient();
	String ServerAppID 					= L"818xxxxxxxx"; // Your FCM App ID
	FPushClient->GCMAppID 			 	= ServerAppID;
	FPushClient->ServerKey 			 	= L"AAAAxxxxxxxxx"; // Your FCM Server Key
	FPushClient->BundleID 			 	= L"com.duolabs.FirebaseCloudMessaging";
	FPushClient->UseSandbox 			= true; // Change this to False for production use!
	FPushClient->OnChange 			 	= &OnServiceConnectionChange;
	FPushClient->OnReceiveNotification 	= &OnReceiveNotificationEvent;
	FPushClient->Active 				= true;
	Memo1->Lines->Add("Requested...");

}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
	/*
	   You Can Run here the Token Request at Startup
	*/
}
//---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
void __fastcall TForm1::OnServiceConnectionChange(TObject *Sender, TPushService::TChanges AChange)
{
	char cValue [512];
	memset (cValue, 0, sizeof(cValue));

	strcat (cValue, "Device ID: ");
	ConvertUnicodeToChar (FPushClient->DeviceID ,cValue+strlen(cValue));

	#if defined(__ANDROID__)
		strcat (cValue, "\r\nAndroid TOKEN: ");
		ConvertUnicodeToChar (FPushClient->DeviceToken ,cValue+strlen(cValue));
	#endif

	#if defined(__APPLE__) && (defined(__arm__) || defined(__arm64__))
		strcat (cValue, "\r\nApple TOKEN: ");
		// APNSToken is shared between Delpi and C++ via SharesVariables.pas
		ConvertUnicodeToChar (APNSToken ,cValue+strlen(cValue));
	#endif


	Memo1->Lines->Add(cValue);

	// Here you can Register the Token Associated with the Device ID in your Database

}
// ---------------------------------------------------------------------------

void __fastcall TForm1::OnReceiveNotificationEvent(TObject *Sender, TPushServiceNotification* const ANotification)
{
 	char cValue [512];
	memset (cValue, 0, sizeof(cValue));
	strcat (cValue, "NEW MESSAGE ARRIVED:\r\n");
	ConvertUnicodeToChar (ANotification->DataObject->ToString() ,cValue+strlen(cValue));
	Memo1->Text = cValue;

	//Memo1->Lines->Add(ANotification->DataObject->ToString);

	const String FCMSignature = L"gcm.notification.body";
	const String GCMSignature = L"message";
	const String APNsSignature = L"alert";
	String aText = "";
	TJSONValue * aObj;

	#if defined(__ANDROID__)
	aObj = ANotification->DataObject->GetValue(GCMSignature);
	if(aObj != NULL)
	{
		aText = aObj->Value();
	}
	else
	{
		aText = ANotification->DataObject->GetValue(FCMSignature)->Value();
	}
	#endif

	#if defined(__APPLE__) && (defined(__arm__) || defined(__arm64__))
	aObj = ANotification->DataObject->GetValue(APNsSignature);
	if (aObj != NULL)
	{
		aText = aObj->Value();
	}
	#endif

	ShowMessage(aText);

}

int ConvertUnicodeToChar (UnicodeString InputUnicode, char * CharString)
{
	 // first convert to AnsiString instead of Unicode.
	AnsiString ansiB(InputUnicode);
	// allocate enough memory for your char array (and the null terminator)
	char* str = new char[ansiB.Length()+1];
	// copy the contents of the AnsiString into your char array
	strcpy(str, ansiB.c_str());

	// Copy String
	strcpy (CharString, str);

	// remember to delete your char array when done
	delete[] str;

	//Return Char Length
	return strlen(CharString);

}
void __fastcall TForm1::TestInternetClick(TObject *Sender)
{
	bool bResult = false;

	bResult = CheckInet();
	if (bResult == true) {
		Memo1->Lines->Add("Internet Connection OK");
	}
	else {
		Memo1->Lines->Add("Internet Connection KO");
	}
}
//---------------------------------------------------------------------------

