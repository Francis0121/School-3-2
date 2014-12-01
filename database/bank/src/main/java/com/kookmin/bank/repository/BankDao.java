package com.kookmin.bank.repository;

import java.util.List;

import org.mybatis.spring.support.SqlSessionDaoSupport;
import org.springframework.stereotype.Repository;

@Repository
public class BankDao extends SqlSessionDaoSupport {

	public List<Branch> selectBranchList() {
		return getSqlSession().selectList("bankSql.selectBranchList");
	}
	
	public List<Client> selectEachBranchSelectClient(){
		return getSqlSession().selectList("bankSql.selectEachBranchSelectClient");
	}

	public List<Client> selectClient(String branchName) {
		return getSqlSession().selectList("bankSql.selectClient", branchName);
	}

}
