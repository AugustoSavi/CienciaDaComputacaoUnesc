package com.example.core;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;
import javax.servlet.http.Cookie;

@WebServlet(name = "LoginServelet", value = "/login-servelet")
public class LoginServelet extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {}

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String email = request.getParameter("email");
        String password = request.getParameter("password");
        Map<String,String> user = new HashMap<String,String>();

        if ("admin".equals(email) && "1".equals(password)){
            user.put(email,password);
            Cookie cookie = new Cookie("user",user.toString());
            response.addCookie(cookie);
            response.sendRedirect("sucesso_login.html");
        }
        else {
            response.sendRedirect("login.html");
        }
    }
}
