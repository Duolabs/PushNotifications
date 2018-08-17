// CodeGear C++Builder
// Copyright (c) 1995, 2017 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'DW.PushClient.pas' rev: 32.00 (Android)

#ifndef Dw_PushclientHPP
#define Dw_PushclientHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <SharedVariables.hpp>
#include <System.PushNotification.hpp>
#include <DW.RegisterFCM.hpp>

//-- user supplied -----------------------------------------------------------

namespace Dw
{
namespace Pushclient
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TPushClient;
//-- type declarations -------------------------------------------------------
enum class DECLSPEC_DENUM TPushSystem : unsigned char { APS, GCM };

typedef void __fastcall (__closure *TRegistrationErrorEvent)(System::TObject* Sender, const System::UnicodeString Error);

#pragma pack(push,4)
class PASCALIMPLEMENTATION TPushClient : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::UnicodeString FBundleID;
	System::UnicodeString FDeviceID;
	System::UnicodeString FDeviceToken;
	System::Pushnotification::TPushService* FPushService;
	TPushSystem FPushSystem;
	Dw::Registerfcm::TRegisterFCM* FRegisterFCM;
	System::UnicodeString FServerKey;
	System::Pushnotification::TPushServiceConnection* FServiceConnection;
	bool FUseSandbox;
	System::Pushnotification::TPushServiceConnection::TChangeEvent FOnChange;
	System::Pushnotification::TPushServiceConnection::TReceiveNotificationEvent FOnReceiveNotification;
	TRegistrationErrorEvent FOnRegistrationError;
	void __fastcall ActivateAsync(void);
	void __fastcall ClearDeviceInfo(void);
	void __fastcall CreatePushService(void);
	void __fastcall DoChange(System::Pushnotification::TPushService::TChanges AChange);
	void __fastcall DoRegistrationError(const System::UnicodeString AError);
	bool __fastcall GetActive(void);
	System::UnicodeString __fastcall GetGCMAppID(void);
	void __fastcall ServiceConnectionChangeHandler(System::TObject* Sender, System::Pushnotification::TPushService::TChanges AChange);
	void __fastcall ServiceConnectionReceiveNotificationHandler(System::TObject* Sender, System::Pushnotification::TPushServiceNotification* const ANotification);
	void __fastcall SetActive(const bool Value);
	void __fastcall SetGCMAppID(const System::UnicodeString Value);
	void __fastcall RegisterFCMRequestCompleteHandler(System::TObject* Sender, const bool Success, const System::UnicodeString RequestResult);
	
public:
	__fastcall TPushClient(void);
	__fastcall virtual ~TPushClient(void);
	__property bool Active = {read=GetActive, write=SetActive, nodefault};
	__property System::UnicodeString BundleID = {read=FBundleID, write=FBundleID};
	__property System::UnicodeString DeviceID = {read=FDeviceID};
	__property System::UnicodeString DeviceToken = {read=FDeviceToken};
	__property System::UnicodeString GCMAppID = {read=GetGCMAppID, write=SetGCMAppID};
	__property TPushSystem PushSystem = {read=FPushSystem, nodefault};
	__property bool UseSandbox = {read=FUseSandbox, write=FUseSandbox, nodefault};
	__property System::UnicodeString ServerKey = {read=FServerKey, write=FServerKey};
	__property System::Pushnotification::TPushServiceConnection::TChangeEvent OnChange = {read=FOnChange, write=FOnChange};
	__property System::Pushnotification::TPushServiceConnection::TReceiveNotificationEvent OnReceiveNotification = {read=FOnReceiveNotification, write=FOnReceiveNotification};
	__property TRegistrationErrorEvent OnRegistrationError = {read=FOnRegistrationError, write=FOnRegistrationError};
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
}	/* namespace Pushclient */
}	/* namespace Dw */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DW_PUSHCLIENT)
using namespace Dw::Pushclient;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DW)
using namespace Dw;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Dw_PushclientHPP
