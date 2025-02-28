#include <windows.h>
#include "nwpdlg.h"
#include "resource.h"


class MyDialog : public Dialog 
{
public:
	POINT koordinate;
protected:
	int IDD()
	{ 
		return IDD_DIALOG1; 
	}
	bool OnInitDialog()
	{
		SetInt(IDC_EDIT1, koordinate.x);
		SetInt(IDC_EDIT2, koordinate.y);
		return true;
	}
	bool OnOK()
	{
		try
		{
			koordinate.x = GetInt(IDC_EDIT1);
			koordinate.y = GetInt(IDC_EDIT2);
		}
		catch (XCtrl)
		{
			return false;
		};
		return true;
	}
	void OnCancel()	{ }
	bool OnCommand(int id, int code) { return false; }
};

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hp, LPSTR cmdLine, int nShow)
{
	MyDialog dlg;
	GetCursorPos(&dlg.koordinate);
	if(dlg.DoModal(hInstance, NULL) == IDOK)
	{
		SetCursorPos(dlg.koordinate.x,dlg.koordinate.y);
	}
	return 0;
}
