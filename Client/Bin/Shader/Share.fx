//���̴������� �߰��� ������ �����ϴ�.

//������� ����̹����� �׳� ����ϴٰ� ���ڱ� �ǰݽ� ���� ������� �ٲ����Ѵٸ� �������̴��� ���������� ü���� �� 
//�ٽ� �⺻���̴��� ���ƿ��Ⱑ ������ (9������ ����)

struct VS_INPUT_COLOR
{
    //�ø�ƽ�� �̸� �ڿ� ���ڸ� �ٿ��ش�. �Ⱥ��ϰ�� �⺻���� 0
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