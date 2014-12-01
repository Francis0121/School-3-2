package com.kookmin.bank.repository;

public class Deposit {

	private Integer depositNumber;

	private String ssn;

	private Integer balance;

	private String branchName;

	public Deposit() {
		super();
	}

	public Integer getBalance() {
		return balance;
	}

	public String getBranchName() {
		return branchName;
	}

	public Integer getDepositNumber() {
		return depositNumber;
	}

	public String getSsn() {
		return ssn;
	}

	public void setBalance(Integer balance) {
		this.balance = balance;
	}

	public void setBranchName(String branchName) {
		this.branchName = branchName;
	}

	public void setDepositNumber(Integer depositNumber) {
		this.depositNumber = depositNumber;
	}

	public void setSsn(String ssn) {
		this.ssn = ssn;
	}

	@Override
	public String toString() {
		return "Deposit [depositNumber=" + depositNumber + ", ssn=" + ssn
				+ ", balance=" + balance + ", branchName=" + branchName + "]";
	}
}
