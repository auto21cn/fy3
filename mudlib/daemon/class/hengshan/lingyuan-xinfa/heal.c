// heal.c

#include <ansi.h>

int exert(object me, object target)
{
	if( me->is_fighting() )
		return notify_fail("ս�����˹����ˣ�������\n");

	if(me->query_skill("lingyuan-xinfa",1)<40)
	return notify_fail("�����Ԫ�ķ�����������û�����ˡ�\n");
	if(me->query("eff_kee")==me->query("max_kee"))
	return notify_fail("������û�����κ��ˡ�\n");
	if( (int)me->query("force")<50)
		return notify_fail("�������������\n");

	if( (int)me->query("eff_kee") < (int)me->query("max_kee") / 2 )
		return notify_fail("���Ѿ����˹��أ�ֻ��һ��������������Σ�գ�\n");

	write( HIW "��ȫ�����ɣ���������ʼ�˹����ˡ�\n" NOR);
	message("vision",
		HIW + me->name() + "�������˹����ˣ�����һ���һ��ף����ã��³�һ����Ѫ����ɫ�������ö��ˡ�\n" NOR,
		environment(me), me);

	me->receive_curing("kee", 10 + (int)me->query_skill("force")/5 );
	me->add("force", -50);
	me->set("force_factor", 0);

	return 1;
}