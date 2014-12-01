package com.kookmin.bank.repository;

public class Branch {

	private String branchName;

	private String branchHead;

	private String address;

	public Branch() {
		super();
	}

	public String getAddress() {
		return address;
	}

	public String getBranchHead() {
		return branchHead;
	}

	public String getBranchName() {
		return branchName;
	}

	public void setAddress(String address) {
		this.address = address;
	}

	public void setBranchHead(String branchHead) {
		this.branchHead = branchHead;
	}

	public void setBranchName(String branchName) {
		this.branchName = branchName;
	}

	@Override
	public String toString() {
		return "Branch [branchName=" + branchName + ", branchHead="
				+ branchHead + ", address=" + address + "]";
	}

}
