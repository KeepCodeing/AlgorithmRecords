
// MFCApplication1Dlg.h: 头文件
//

#pragma once


// CMFCApplication1Dlg 对话框
class CMFCApplication1Dlg : public CDialogEx
{
// 构造
public:
	CMFCApplication1Dlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOpenServerBtn();
	afx_msg void OnBnClickedCloseServerBtn();
	afx_msg void OnEnChangeServerPort();
	afx_msg void OnIpnFieldchangedServerIpAddress(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnIpnFieldchangedClientIpAddress(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnEnChangeClientPort();
	afx_msg void OnStnClickedImageBox();
	afx_msg void OnEnChangeCarNumber();
	afx_msg void OnEnChangeCarAngleSpeed();
	afx_msg void OnEnChangeCarLinerSpeed();
	afx_msg void OnEnChangeCarStatus();
	afx_msg void OnEnChangeCarStage();
	afx_msg void OnEnChangeCarX();
	afx_msg void OnEnChangeCarY();
	afx_msg void OnEnChangeCarAngle();
	afx_msg void OnBnClickedInitWaitBtn();
	afx_msg void OnBnClickedGetGoodsBtn();
	afx_msg void OnBnClickedPutGoodsBtn();
	afx_msg void OnEnChangeInitX();
	afx_msg void OnEnChangeInitY();
	afx_msg void OnEnChangeGetGoodsX();
	afx_msg void OnEnChangeGetGoodsY();
	afx_msg void OnEnChangePutGoodsX();
	afx_msg void OnEnChangePutGoodsY();
};
