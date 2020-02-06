# 带Q_OBJECT的.h文件，需要用moc处理，处理后得到.h.moc.cpp，
这个.h.moc.cpp也需要拉进工程。
在.h对应的.cpp中写：
	// using nocheck cityscape.h.moc.cpp
	// cpps-make cityscape.h.moc.cpp : cityscape.h // moc cityscape.h -o cityscape.h.moc.cpp

有些对话框的.h文件中包含了从.ui文件生成的`ui_*.h`文件，从.ui文件生成`ui_*.h`文件的步骤应该放在对话框的.cpp文件中
// cpps-make ui_gotocelldialog.h : gotocelldialog.ui // uic gotocelldialog.ui -o ui_gotocelldialog.h


有些.cpp文件中会使用资源文件.qrc，.qrc经由rcc得到.qrc.rcc.cpp,
这个.qrc.rcc.cpp也需要拉进工程
// using nocheck spreadsheet.qrc.rcc.cpp
// cpps-make spreadsheet.qrc.rcc.cpp : spreadsheet.qrc // rcc spreadsheet.qrc -o spreadsheet.qrc.rcc.cpp




# 已经支持cpps执行的例子：
	chap03
	chap08
	