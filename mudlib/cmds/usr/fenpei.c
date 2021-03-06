inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string skl,what;
	int hard,point,qn,lv,all,left;
	mapping ln,skills;

	qn=(int)me->query("wgjn");
	if(! arg)	{
		write("目前你还剩"+qn+"点武功技能可供分配。\n");
		return 1;
	}
	if( sscanf(arg,"%s %s",skl,what)!=2)
		return notify_fail("请使用help fenpei查看本指令说明。\n");
	skills=me->query_skills();
	if( !mapp(skills))	skills=([]);
	if(! skills[skl])
		return notify_fail("你并没有学会这门武功，无法为其分配技能点数。\n");
	if((string)SKILL_D(skl)->type()!="martial")
		return notify_fail("你只能对武功使用些指令。\n");
	lv=(int)me->query_skill(skl,1);
	if(lv>=2000)
		return notify_fail("这门武功已经达到最高等级了。\n");
	if( !(hard=SKILL_D(skl)->hard_point()))		hard=1;
	ln=me->query_learned();
	all=(lv+1)*(lv+1)*hard*hard;
	left=all-(int)ln[skl];
	if(what=="?")		{
		if(lv<30)	write("这门武功还需"+(left+1)+"技能点便可升一级了。\n");
		else	{
			if(left<=0)	write("你的这门武功已经达到升级(shengji)条件了。\n");
			else		write("这门武功要升级(shengji)还需技能点数"+left+"点。\n");
		}
		return 1;
	}
	if( sscanf(what,"%d",point)!=1)
		return notify_fail("请使用help fenpei查看本指令说明。\n");
	if(point>qn)
		return notify_fail("你的武功技能点数不够！\n");
	if(point<=0)
		return notify_fail("分配的武功技能点数至少为1点！\n");
	if(left<=0 && lv>=30)		write("你的这门武功已经达到升级(shengji)条件了。\n");
	else	{
		me->add("wgjn",-point);
		me->improve_skill(skl,point,1);
		write("你对"+to_chinese(skl)+"分配了"+point+"点技能。\n");
	}
	return 1;
}

int help(object me)
{
        write(@HELP

指令格式：
fenpei <武功名称> <技能点数>
	将技能点数分配给指定的武功。
fenpei <武功名称> <?>
	查看指定武功升级所需的技能点数。
fenpei
	查看你所剩的武功技能点数。

在你每次成功完成任务之后会获得武功技能点数的奖励。
本指令可以让你根据需要，把获得的武功技能点数分配
给你想要发展的武功上。


HELP
        );
        return 1;
}


