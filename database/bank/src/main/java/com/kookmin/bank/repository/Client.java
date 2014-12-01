package com.kookmin.bank.repository;

public class Client {

	private String ssn;

	private String name;

	private String address;

	private String phone;

	private Deposit deposit;

	public Client() {
		super();
		deposit = new Deposit();
	}

	public String getAddress() {
		return address;
	}

	public Deposit getDeposit() {
		return deposit;
	}

	public String getName() {
		return name;
	}

	public String getPhone() {
		return phone;
	}

	public String getSsn() {
		return ssn;
	}

	public void setAddress(String address) {
		this.address = address;
	}

	public void setDeposit(Deposit deposit) {
		this.deposit = deposit;
	}

	public void setName(String name) {
		this.name = name;
	}

	public void setPhone(String phone) {
		this.phone = phone;
	}

	public void setSsn(String ssn) {
		this.ssn = ssn;
	}

	@Override
	public String toString() {
		return "Client [ssn=" + ssn + ", name=" + name + ", address=" + address
				+ ", phone=" + phone + ", deposit=" + deposit + "]";
	}

}
