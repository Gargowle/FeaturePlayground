#pragma once


class STabToolPanel : public SCompoundWidget
{
	SLATE_BEGIN_ARGS(STabToolPanel)
	{}
	SLATE_ARGUMENT(TWeakPtr<class FTabTool>, Tool)
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);

protected:
	TWeakPtr<FTabTool> tool;
};
