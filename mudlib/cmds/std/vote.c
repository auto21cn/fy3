// vote command..
// Modified by Marz, 04/18/96

#include <ansi.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	object victim;
	string mode, victim_name;
	string *data;
	int count;

	if( !arg)	return notify_fail("请看帮助文件。\n");
	if( me->query("age")<16 && !wizardp(me))
		return notify_fail("你年纪太小啦！\n");
	if( sscanf(arg,"%s %s",mode,victim_name)!=2)
		return notify_fail("请看帮助文件。\n");
	if( mode!="-c" && mode!="-o")
		return notify_fail("请看帮助文件。\n");
	if( victim_name==me->query("id"))
		return notify_fail("有没有搞错？\n");
	if( me->query("bad_chat"))
		return notify_fail("你无权投票！\n");
	if( time()-(int)me->query("vote_time")<60)
		return notify_fail("你刚行使过投票权，过一分钟再说吧。\n");
	if( !wizardp(me))
		me->set("vote_time",time());

	victim=find_player(victim_name);
	if( !objectp(victim))
		return notify_fail("没有这么个人。\n");
	if( wizardp(victim))
		return notify_fail("你无权对巫师投票！\n");
	if( mode=="-c"&& (int)victim->query("bad_chat"))
		return notify_fail(victim->query("name")+"的聊天权力早已被关闭。\n");
	if( mode=="-o" && !(int)victim->query("bad_chat"))
		return notify_fail(victim->query("name")+"的聊天权力早就开放了。\n");
	if( mode=="-c")	{
		data=victim->query("close_chat");
		if( !sizeof(data))	data=({});
		if( member_array(me->query("id"),data)!=-1)
			return notify_fail("你已投过关闭"+victim->query("name")+"聊天权力的一票了。\n");
		data+=({ me->query("id") });
		victim->set("close_chat",data);
		count=5-sizeof(data);
		victim->apply_condition("vote_clean",10);
		if(count>0)
		message("channel:chat",HIC"【闲聊】"+me->query("name")+"投票关闭"+
		victim->query("name")+"的聊天权力，还差"+chinese_number(count)+
		"票！\n"NOR,users());
		else	{
		message("channel:chat",HIC"【闲聊】"+me->query("name")+"投票关闭"+
		victim->query("name")+"的聊天权力，"+victim->query("name")+
		"的聊天权力被关闭了！\n"NOR,users());
		victim->set("bad_chat",1);
		victim->delete("close_chat");
		victim->apply_condition("vote_clean",-10);
		}
	}
	else	{
		data=victim->query("open_chat");
		if( !sizeof(data))	data=({});
		if( member_array(me->query("id"),data)!=-1)
			return notify_fail("你已投过开放"+victim->query("name")+"聊天权力的一票了。\n");
		data+=({ me->query("id") });
		victim->set("open_chat",data);
		count=5-sizeof(data);
		victim->apply_condition("vote_clean",10);
		if(count>0)
		message("channel:chat",HIC"【闲聊】"+me->query("name")+"投票开放"+
		victim->query("name")+"的聊天权力，还差"+chinese_number(count)+
		"票！\n"NOR,users());
		else	{
		message("channel:chat",HIC"【闲聊】"+me->query("name")+"投票开放"+
		victim->query("name")+"的聊天权力，"+victim->query("name")+
		"的聊天权力被恢复了！\n"NOR,users());
		victim->delete("bad_chat");
		victim->delete("open_chat");
		victim->apply_condition("vote_clean",-10);
		}
	}
	return 1;
}

int help(object me)
{
write(@HELP
指令格式 : vote [-c|-o] <某人> 

此命令提议对某人采取行动，由大家投票决定。可是如果五分钟内没有人附议，
投票会自动取消。投票后的玩家需过一分钟后才能再次投票。

-c: 关闭某人交谈频道，需五票同意。
-o: 打开某人交谈频道，需五票同意。

HELP
    );
    return 1;
}
