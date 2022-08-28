#include "TabToolPanel.h"

#include "Widgets/Layout/SScrollBox.h"

void STabToolPanel::Construct(const FArguments& InArgs)
{
	tool = InArgs._Tool;
	if (tool.IsValid())
	{
		// here is the space to do anything that needs to be done to setup the tool object properly
	}

	ChildSlot
	[
		SNew(SScrollBox)
		+ SScrollBox::Slot()
		.VAlign(VAlign_Top)
		.Padding(5)
		[
			SNew(SBorder)
			.BorderBackgroundColor(FColor(192, 192, 192))
			.Padding(15.0f)
			[
				SNew(STextBlock)
				.Text(FText::FromString(TEXT("This is a tab example.")))
			]
		]
	];
}
