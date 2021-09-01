package com.example.core;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.annotation.*;
import java.io.IOException;
import java.io.PrintWriter;

@WebServlet(name = "SomaServlet", value = "/soma-servlet")
public class SomaServlet extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        Integer valor1 = Integer.valueOf(request.getParameter("elemento1"));
        Integer valor2 = Integer.valueOf(request.getParameter("elemento2"));
        System.out.println(valor1+valor2);
        PrintWriter out = response.getWriter();
        out.println("soma:"+(valor1+valor2));
    }
}
