//���̴������� �߰��� ������ �����ϴ�.

//������� ����̹����� �׳� ����ϴٰ� ���ڱ� �ǰݽ� ���� ������� �ٲ����Ѵٸ� �������̴��� ���������� ü���� �� 
//�ٽ� �⺻���̴��� ���ƿ��Ⱑ ������ (9������ ����)

//���� �ڿ� : (�ø�ƽ)

//���̴��� 1��¥���ڵ�� ������ŭ ����Ǳ⶧���� ������¥���� �ƴϴ�
//���ؽ��� 2������� ����¥���ڵ尡 2����¥�� �ڵ尡�ȴ�.

struct VS_INPUT_COLOR
{
    //�ø�ƽ�� �̸� �ڿ� ���ڸ� �ٿ��ش�. �Ⱥ��ϰ�� �⺻���� 0
    //�����̸� ������ : ��Ʈ�ʵ�(��Ʈ��)
    float3 vPos : POSITION; 
    float4 vColor : COLOR;
};

struct VS_OUTPUT_COLOR
{
    //SV = SystemValue -> �ٲ� �� ����.
    float4 vPos : SV_POSITION;
    float4 vColor : COLOR;
};

struct PS_OUTPUT_SINGLE
{
    float4 vTarget0 : SV_Target;
};

//CBuffer�� ������� (C++�ڵ忡�� ���̴��� ���� �޾ƿ��� ����)
//cbuffer �Լ��� : �������Ϳ� b0�� �����ϰڴ�.
cbuffer Transform : register(b0)
{
    matrix g_World;       //�������
    matrix g_View;        //�����
    matrix g_Projection;  //�������

    //�ΰ��� �� �����ϴ� ������ ���ؽ����� ���� �ͺ���
    //�̹� ������ ���� ���ͼ� �����ϴ°� �ξ��� �����⶧���̴�.
    matrix g_WV;    //World * View
    matrix g_WVP;   //World * View * Projection
}