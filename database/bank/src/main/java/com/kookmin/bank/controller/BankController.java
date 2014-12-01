package com.kookmin.bank.controller;


import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;

import com.kookmin.bank.repository.BankDao;
import com.kookmin.bank.repository.Branch;
import com.kookmin.bank.repository.Client;

@Controller
public class BankController {
	
	@Autowired
	private BankDao bankDao;
	
	private static final Logger logger = LoggerFactory.getLogger(BankController.class);
	
	@RequestMapping(value = "/", method = RequestMethod.GET)
	public String bank(Model model) {
		logger.debug("Bank");
		
		// ~ Sql 질의문 2개를 이용하여 해당 정보 조회
		List<Client> clients = bankDao.selectEachBranchSelectClient();
		List<Branch> branches = bankDao.selectBranchList();
		
		HashMap<String, List<Client>> clientMap = new HashMap<String, List<Client>>();
		for(Branch b : branches){
			List<Client> newClient = new ArrayList<Client>();
			for(Client c : clients){
				if(b.getBranchName().equals(c.getDeposit().getBranchName())){
					newClient.add(c);
				}
			}
			clientMap.put(b.getBranchName(), newClient);
		}
		
		model.addAttribute("branches", branches);
		model.addAttribute("clientMap", clientMap);
		
		// ~ 여러번 질의를 날려 정보를 조회 
		List<Branch> branches2 = bankDao.selectBranchList();
		
		HashMap<String, List<Client>> clientMap2 = new HashMap<String, List<Client>>();
		for(Branch b : branches2){
			List<Client> clients2 = bankDao.selectClient(b.getBranchName());
			clientMap2.put(b.getBranchName(), clients2);
		}

		model.addAttribute("branches2", branches2);
		model.addAttribute("clientMap2", clientMap2);		
		
		return "bank";
	}

}

