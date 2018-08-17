// CodeGear C++Builder
// Copyright (c) 1995, 2017 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'DW.RegisterFCM.pas' rev: 32.00 (Android)

#ifndef Dw_RegisterfcmHPP
#define Dw_RegisterfcmHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <System.Classes.hpp>

//-- user supplied -----------------------------------------------------------

namespace Dw
{
namespace Registerfcm
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TRegisterFCM;
//-- type declarations -------------------------------------------------------
typedef void __fastcall (__closure *TFCMRequestCompleteEvent)(System::TObject* Sender, const bool Success, const System::UnicodeString RequestResult);

#pragma pack(push,4)
class PASCALIMPLEMENTATION TRegisterFCM : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TFCMRequestCompleteEvent FOnRequestComplete;
	void __fastcall DoParseResult(const System::UnicodeString AContent);
	void __fastcall DoRequestComplete(const bool ASuccess, const System::UnicodeString ARequestResult);
	void __fastcall DoRegister(const System::UnicodeString AServerKey, System::Classes::TStream* const ARequest);
	void __fastcall DoRegisterAPNToken(const System::UnicodeString AServerKey, const System::UnicodeString ARequest);
	
public:
	void __fastcall RegisterAPNToken(const System::UnicodeString AAppBundleID, const System::UnicodeString AServerKey, const System::UnicodeString AToken, const bool ASandbox = false);
	__property TFCMRequestCompleteEvent OnRequestComplete = {read=FOnRequestComplete, write=FOnRequestComplete};
public:
	/* TObject.Create */ inline __fastcall TRegisterFCM(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TRegisterFCM(void) { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
}	/* namespace Registerfcm */
}	/* namespace Dw */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DW_REGISTERFCM)
using namespace Dw::Registerfcm;
#endif
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DW)
using namespace Dw;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Dw_RegisterfcmHPP
