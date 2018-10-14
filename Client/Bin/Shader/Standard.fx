#include "Share.fx"

//fx파일은 버텍스와 픽셀쉐이더 두개 동시에 처리가 가능하다.

VS_OUTPUT_COLOR StandardColorVS(VS_INPUT_COLOR input)
{
    //0으로 초기화
    VS_OUTPUT_COLOR output = (VS_OUTPUT_COLOR)0;

    output.vPos = float4(input.vPos, 1.0f);
    output.vColor = input.vColor;

    return output;
}

//버텍스 쉐이더에서 뱉은 OutPut데이터가 픽셀쉐이더 Input으로 들어온다. (매쉬클래스 랜더에서 이미 다 지정을 해놨다(IA~) )
PS_OUTPUT_SINGLE StandardColorPS(VS_OUTPUT_COLOR input)
{
    PS_OUTPUT_SINGLE output = (PS_OUTPUT_SINGLE)0;

    output.vTarget0 = input.vColor;

    return output;
}


