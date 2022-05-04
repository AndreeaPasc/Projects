FROM gradle:jdk11-alpine AS builder

WORKDIR /app
COPY --chown=gradle:gradle . /app

RUN ./gradlew assemble --stacktrace
RUN java -Djarmode=layertools -jar /app/build/libs/final-project-AndreeaPasc-0.0.1-SNAPSHOT.jar list
RUN java -Djarmode=layertools -jar /app/build/libs/final-project-AndreeaPasc-0.0.1-SNAPSHOT.jar extract
RUN ls -l /app

FROM openjdk:11.0.6-jre

ENV DB_IP: desilxl0nthgloe1y.chr7pe7iynqr.eu-west-1.rds.amazonaws.com
ENV DB_PORT: 3306
ENV DB_USER: kxmqv2ti8jvkljhv
ENV DB_PASSWORD: hynkklknm3a7wzmm
ENV DB_DBNAME: t6aaptoge9tx1wpk

COPY --from=builder /app/dependencies .
COPY --from=builder /app/snapshot-dependencies .

RUN sleep 10
COPY --from=builder /app/spring-boot-loader .
COPY --from=builder /app/application .

ENTRYPOINT ["java", "org.springframework.boot.loader.JarLauncher","-XX:+UseContainerSupport -XX:+UnlockExperimentalVMOptions"]