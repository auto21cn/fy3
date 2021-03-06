inherit F_CLEAN_UP;
inherit F_BH;
int main(object me, string arg)
{
        object ob;
	mapping data;
	string banghui,file="/data/banghui/";
	int flag;
	if( (banghui=me->query("banghui"))&&
		check_file(file+banghui))
		return notify_fail("抱歉，你已经是帮会「"+me->query("banghui")+"」的人了，无法加入其他帮会。\n");
	if( (banghui=me->query("banghui"))&&
		! check_file(file+banghui))
		return notify_fail("你的帮会文件丢失，请与巫师联系。\n");
	if(me->is_fighting()||me->is_busy())
		return notify_fail("你正忙着呢。\n");
	if(! arg)
		return notify_fail("你要加入谁的帮会？\n");
	if( me->query("id")==arg)
		return notify_fail("你没法这么做！\n");
	if(! objectp(ob=present(arg,environment(me))))
		return notify_fail("这儿没有这么个人。\n");
	if(! userp(ob))
		return notify_fail("你只能加入玩家组织的帮会。\n");
	if((object)me->query_temp("target")!=ob)
		return notify_fail("抱歉，"+ob->query("name")+"并没有邀请你参加他的帮会。\n");
	if(! (banghui=ob->query("banghui")))
		return notify_fail("抱歉，"+ob->query("name")+"现在不属于任何帮会！\n");
	if(! check_file(file+banghui))
		return notify_fail("对方帮会文件丢失，请与巫师联系。\n");
	data=get_file_data(file+banghui);
	data["player"]++;
	if(! save_file_data(data,file+banghui))
		return notify_fail("帮会文件写入出错，请与巫师联系。\n");
	message_vision("$N决定加入$n的帮会「"+ob->query("banghui")+"」！\n",me,ob);
	me->set("banghui",ob->query("banghui"));
	me->delete_temp("target");
	return 1;
}
int help(object me)
{
        write(@HELP
指令格式：jiaru <某人>
这个指令用来加入某人的帮会。
前提是某人必须邀请你。
HELP
        );
        return 1;
}
