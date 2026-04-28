//---------------------------------------------------------------------------
#include <windows.h>

#include "tp_stub.h"
	// tp_stub.h と tp_stub.cpp は必ずプロジェクトに追加する

#include "wave.h"
#include "mosaic.h"
#include "turn.h"
#include "rotatetrans.h"
#include "ripple.h"

//---------------------------------------------------------------------------
// STDCALL macro for Windows DLL export
#ifdef _MSC_VER
    #define DLL_EXPORT  __declspec(dllexport)
#else
    #define DLL_EXPORT  __attribute__((visibility("default")))
#endif
#define EXPORT(hr) extern "C" DLL_EXPORT hr STDCALL

//---------------------------------------------------------------------------
// V2Link は DLL がリンクされるときに実行される
EXPORT(HRESULT) V2Link(iTVPFunctionExporter *exporter)
{
	// スタブの初期化
	TVPInitImportStub(exporter); // 必ずこれは記述
	/*
		TVPInitImpotStub を実行した後は吉里吉里内部の各関数や tTJSVariant 等の
		基本的な型が使用可能になる。
	*/

	// トランジションハンドラプロバイダの登録
	RegisterWaveTransHandlerProvider();
	RegisterMosaicTransHandlerProvider();
	RegisterTurnTransHandlerProvider();
	RegisterRotateTransHandlerProvider();
	RegisterRippleTransHandlerProvider();

	return S_OK;
}
//---------------------------------------------------------------------------
// V2Unlink は DLL がアンリンクされるときに実行される
EXPORT(HRESULT) V2Unlink()
{
	// トランジションハンドラプロバイダの登録削除
	UnregisterWaveTransHandlerProvider();
	UnregisterMosaicTransHandlerProvider();
	UnregisterTurnTransHandlerProvider();
	UnregisterRotateTransHandlerProvider();
	UnregisterRippleTransHandlerProvider();

	// スタブの使用終了
	TVPUninitImportStub(); // 必ずこれは記述
	/*
		TVPUninitImpotStub は TVPInitImportStub で確保したメモリを解放する
		ので必ず記述する。
	*/
	return S_OK;
}
//---------------------------------------------------------------------------

