# PushNotifications
Push Notification using Embarcadero Rad Studio Tokyo 10.2.3 on Android and Apple Deviced written in C++ and Delphi.


# Premise:
This project is based on C++ code and Delphi code. The main core application is meant to be developed in C++ using Delphi code as separate units to accomplish to the result. This document is dedicated to all those who tried hard to make their own Push Notification using Embarcadero Rad Studio and it is tested on version Tokyo 10.2.3 with an Android SM-520 (Galaxy  A5) and iPhone X (iOS 11.4.1)

* A detailed Guide can be found in the DOC Directory

_File needed:

• Delphi

DW.iOSapi.UserNotifications.pas
DW.iOSapi.UserNotifications.hpp

DW.RemoteNotificationsPatch.iOS.pas
DW.RemoteNotificationsPatch.iOS.hpp

DW.PushClient.pas
DW.PushClient.hpp

DW.RegisterFCM.pas
DW.RegisterFCM.hpp

SharedVariables.pas
SharedVariables.hpp

•	C++

Unit1.cpp
Unit1.h


Android. To send Push Notifications on Android you need to create a Firebase Cloud Messaging account and using the console (login) you need to create your own APP and assign to it an application identifier which must be the same on the final application (ex. com.duolabs.mypushapp)
iOS. On iOS you need to create a Push Certificate on Apple Developers Site which allows you to send push notifications to a specific Application within the same range of application domain (ex. com.duolabs.mypushapp)
Notifications for Android needs to have a FCM account and notification for Apple must have an AppID and a Push Cerificate.
We are going to send Push Messages using two .php scripts, one for Android and one for iOS.


Little code Explanation.

C++ Code:

Functions: 

bool __fastcall CheckInet();

_Checks if internet connection is available. Not so interesting.


void __fastcall TForm1::ResendRequestButClick(TObject *Sender)
_Requests for Mobile Device Application to be registered through FCM to FCM and APN Servers and triggers function once OnServiceConnectionChange the Token is received: 

Variables:
	
	String ServerAppID 		= L"8189xxxxxxxxx";
	FPushClient->GCMAppID 		= ServerAppID;
	FPushClient->ServerKey 		= L"AAAAxxxxxxx";
	FPushClient->BundleID 		= L"com.duolabs.mypushapp";
	FPushClient->UseSandbox 	= true;	
  	FPushClient->OnChange 		= &OnServiceConnectionChange;
	FPushClient->OnReceiveNotification 	= &OnReceiveNotificationEvent;
	FPushClient->Active 		  = true;


void __fastcall TForm1::OnServiceConnectionChange(TObject *Sender, TPushService::TChanges AChange)

_When a Token is received. Android Token is received in FCM format (long String) and Apple Token is returned in HEX format (32Bytes). Apple Token value is passed from Delphi to C++ using “String APNSToken“ declared in SharedVariables.pas


void __fastcall TForm1::ResendRequestButClick(TObject *Sender)

_Requests for Mobile Device Application to be registered through FCM to FCM and APN Servers and triggers function: 


void __fastcall TForm1::OnReceiveNotificationEvent(TObject *Sender, TPushServiceNotification* const ANotification)

_This function triggers when a notification message is received



# Notes and TroubleShooting

•	Device ID remains the same on every device and is sent to APN or FCM to obtain a Token for Remote Push Notification. Token changes every time the Application is installed (fresh installation). If you register on a DB the Token remember to update and check it every time the Mobile Application starts as it may have changed due to a re-installation of the Application (Remove->Install). 

•	This C++ Application is based on Delphi source code (credits to Dave Nottage@ Delphi World). 
A warm thank you and my appreciations to Dave Nottage for his time and patience it paid off to me! Don’t forget to have a look at his awesome WebSite for Delphi Lovers!!

•	A good guide for APN registration can be found here: https://www.raywenderlich.com/584-push-notifications-tutorial-getting-started

•	We decided not avoid FCM SDK to avoid the fact of being to tied to Google’s services which are and remains great but having more control on the Push Notification sets the developer free to act the way he wants. 

Have fun and enjoy. 
Any feedback will be very appreciated.
Riccardo Alessi
